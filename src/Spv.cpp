#include <iostream>

#include "Spv.hpp"
#include "Assert.hpp"
#include "Array.hpp"

/*
    TODO:(Sol): 
    1. Forward referencing in spirv
*/

namespace Sol {

static const uint32_t magic = 0x07230203;
static LinearAllocator *scratch = &MemoryService::instance()->scratch_allocator;

Spv::Type* Spv::get_type(uint32_t id) {
    for(int i = 0; i < types.len; ++i) {
        if (id == types[i].id)
            return &types[i];
    }
    return nullptr;
}

Spv Spv::parse(size_t code_size, const uint32_t *spirv)
{
    Spv ret = {};
    if (spirv[0] != magic) {
        ret.stage = NONE;
        //ret.stage = VK_SHADER_STAGE_ALL;
        return ret;
    }

    ret.scratch_mark = scratch->get_mark();

#if SPV_DEBUG
    DebugInfo debug = {};
    ret.debug.init(16);
#endif

    ret.types.init(16);
    // Avoid multiple constr/destr calls
    Type type = {};
    Var var = {};

    uint16_t inc = 5;
    while (inc < code_size / 4) {
        const uint16_t *info = reinterpret_cast<const uint16_t*>(spirv + inc);
        const uint32_t *instr = spirv + inc;

        switch (info[0]) {
        // stage
			case 15: 
            {
				// TODO:(Sol): Support other shader stages
				const uint32_t *model = instr + 1;
				switch (*model) {
				case 0:
					//ret.stage = VK_SHADER_STAGE_VERTEX_BIT;
					ret.stage = VERT;
					break;
				case 4:
					//ret.stage = VK_SHADER_STAGE_FRAGMENT_BIT;
					ret.stage = FRAG;
					break;
				default:
					break;
				}
				ret.p_name = reinterpret_cast<const char*>(model + 2);
				break;
			}
            // OpDecorate
            case 71:
            {
                uint32_t id = *(instr + 1);
                Deco deco = static_cast<Deco>(*(instr + 2));
                uint32_t literal = *(instr + 3);

                Type* type_ref = ret.get_type(id);
                if (!type_ref) {
                    type = {};
                    type.id = id;
                    type.name = Name::VAR;
                    type.data = lin_alloc(sizeof(var));

                    var = {};
                    mem_cpy(type.data, &var, sizeof(var));

                    ret.types.push(type);
                    type_ref = ret.types.last();
                }
                Var *var_ref = reinterpret_cast<Var*>(type_ref->data);

                switch(deco) {
                    case Deco::BLOCK:
                    {
                        var_ref->deco_info.flags |= static_cast<uint32_t>(DecoFlagBits::BLOCK);
                        break;
                    }
                    case Deco::ROW_MAJOR:
                    {
                        var_ref->deco_info.flags |= static_cast<uint32_t>(DecoFlagBits::ROW_MAJOR);
                        break;
                    }
                    case Deco::COL_MAJOR:
                    {
                        var_ref->deco_info.flags |= static_cast<uint32_t>(DecoFlagBits::COL_MAJOR);
                        break;
                    }
                    case Deco::ARRAY_STRIDE:
                    {
                        var_ref->deco_info.flags |= static_cast<uint32_t>(DecoFlagBits::ARRAY_STRIDE);
                        var_ref->deco_info.array_stride = literal;
                        break;
                    }
                    case Deco::MAT_STRIDE:
                    {
                        var_ref->deco_info.flags |= static_cast<uint32_t>(DecoFlagBits::MAT_STRIDE);
                        var_ref->deco_info.mat_stride = literal;
                        break;
                    }
                    case Deco::BUILTIN:
                    {
                        var_ref->deco_info.flags |= static_cast<uint32_t>(DecoFlagBits::BUILTIN);
                        break;
                    }
                    case Deco::CONSTANT:
                    {
                        var_ref->deco_info.flags |= static_cast<uint32_t>(DecoFlagBits::CONSTANT);
                        break;
                    }
                    case Deco::UNIFORM:
                    {
                        var_ref->deco_info.flags |= static_cast<uint32_t>(DecoFlagBits::UNIFORM);
                        break;
                    }
                    case Deco::LOCATION:
                    {
                        var_ref->deco_info.flags |= static_cast<uint32_t>(DecoFlagBits::LOCATION);
                        var_ref->deco_info.location = literal;
                        break;
                    }
                    case Deco::COMPONENT:
                    {
                        var_ref->deco_info.flags |= static_cast<uint32_t>(DecoFlagBits::COMPONENT);
                        var_ref->deco_info.component = literal;
                        break;
                    }
                    case Deco::BINDING:
                    {
                        var_ref->deco_info.flags |= static_cast<uint32_t>(DecoFlagBits::BINDING);
                        var_ref->deco_info.binding = literal;
                        break;
                    }
                    case Deco::DESC_SET: 
                    {
                        var_ref->deco_info.flags |= static_cast<uint32_t>(DecoFlagBits::DESC_SET);
                        var_ref->deco_info.desc_set = literal;
                        break;
                    }
                    case Deco::OFFSET:
                    {
                        var_ref->deco_info.flags |= static_cast<uint32_t>(DecoFlagBits::OFFSET);
                        var_ref->deco_info.offset = literal;
                        break;
                    }
                    default:
                        break;
                }

                break;
            }
            // OpMemberDecorate
            case 72:
            {
                // TODO:(Sol): 
                break;
            }
            // OpVar
            case 59:
            {
                // TODO:(Sol):
                break;
            }


#if SPV_DEBUG
            // OpName
            case 5:
            {
                debug.id = *(instr + 1);
                debug.name = reinterpret_cast<const char*>(instr + 2);
                ret.debug.push(debug);

                break;
            }
#endif
        }

        inc += info[1];
    }
    return ret;
}


// TODO:(Sol): Loop through pointers to find their types

void Spv::kill() {
    scratch->cut_diff(scratch_mark);
    types.kill();

#if SPV_DEBUG
    debug.kill();
#endif
}

} // namespace Sol
