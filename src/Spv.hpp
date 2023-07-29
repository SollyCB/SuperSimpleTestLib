#pragma once 

#include <cstdint>
#include <cstddef>
//#include <vulkan/vulkan.hpp>

#include "Vec.hpp"
#include "Allocator.hpp"

namespace Sol {
	
struct Spv {
    enum Stage {
        NONE,
        VERT,
        FRAG,
    };
    enum class Name {
        BOOL = 20,
        INT = 21,
        FLOAT = 22,
        VAR = 59,
    };
    enum class Storage {
        UNIFORM_CONSTANT = 0,
        INPUT = 1,
        UNIFORM = 2,
        OUTPUT = 3,
        PUSH_CONSTANT = 9,
        IMAGE = 11,
        STORAGE_BUFFER = 12,
    };
    enum class DecoFlagBits : uint32_t {
        BLOCK = 0x0001,
        ROW_MAJOR = 0x0002,
        COL_MAJOR = 0x0004,
        ARRAY_STRIDE = 0x0008,
        MAT_STRIDE = 0x0010,
        BUILTIN = 0x0020,
        CONSTANT = 0x0040,
        UNIFORM = 0x0080,
        LOCATION = 0x0100,
        COMPONENT = 0x0200,
        BINDING = 0x0400,
        DESC_SET = 0x0800, 
        OFFSET = 0x1000,
    };
    struct Type {
        uint32_t id = UINT32_MAX;
        Name name;
        void *data;
    };
    struct DecoInfo {
        uint32_t flags = 0x0;
        int array_stride = -1;
        int mat_stride = -1;
        int location = -1;
        int component = -1;
        int binding = -1;
        int desc_set = -1;
        int offset = -1;
    };
    struct Var {
        int type_id = -1;
        Storage storage;
        DecoInfo deco_info;
    };

    // Member objects
    // TODO:Sol: edit returned stage
    // VkShaderStageFlagBits stage = VK_SHADER_STAGE_ALL;
    Stage stage = NONE;
    const char* p_name = nullptr;
    Vec<Type> types;

    static Spv parse(size_t code_size, const uint32_t *spirv);
	void kill();

private:
    enum class Deco : uint32_t {
        BLOCK = 2,
        ROW_MAJOR = 4,
        COL_MAJOR = 5,
        ARRAY_STRIDE = 6,
        MAT_STRIDE = 7,
        BUILTIN = 11,
        CONSTANT = 22,
        UNIFORM = 26,
        LOCATION = 30,
        COMPONENT = 31,
        BINDING = 33,
        DESC_SET = 34, 
        OFFSET = 35,
    };
    size_t scratch_mark = 0;
    Type* get_type(uint32_t id);

#if SPV_DEBUG
    struct DebugInfo {
        uint32_t id;
        const char *name;
    };
    Vec<DebugInfo> debug;
#endif
};

} // namespace Sol
