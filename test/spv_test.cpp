#include "test.hpp"
#include "spv_test.hpp"
#include "Spv.hpp"
#include "File.hpp"
#include "Allocator.hpp"
#include <cstdint>
#include <cstddef>

namespace Sol {
    static const bool SKIP = true;

    void test_triangle3(bool skip) {
        size_t code_size = 0;
        const uint32_t *pcode = File::read_spv(&code_size, "triangle3.vert.spv", HEAP);
        Spv spv = Spv::parse(code_size, pcode);

        using Flags = Spv::DecoFlagBits;

        Spv::Var ubo = *(reinterpret_cast<Spv::Var*>(spv.types[2].data));
        uint32_t deco_flags_binding = static_cast<uint32_t>(Flags::BINDING);
        uint32_t deco_flags_desc_set = static_cast<uint32_t>(Flags::DESC_SET);
        TEST_EQ("UboFlags", ubo.deco_info.flags, deco_flags_binding | deco_flags_desc_set, skip);

        Spv::Var in_color = *(reinterpret_cast<Spv::Var*>(spv.types[5].data));
        uint32_t deco_flags_location = static_cast<uint32_t>(Flags::LOCATION);
        TEST_EQ("InColorFlags", in_color.deco_info.flags, deco_flags_location, skip);
        TEST_EQ("InColorLocation", in_color.deco_info.location, 1, skip);

        Spv::Var tex_sampler = *(reinterpret_cast<Spv::Var*>(spv.types[6].data));
        TEST_EQ("TexSamplerFlags", tex_sampler.deco_info.flags, deco_flags_binding | deco_flags_desc_set, skip);
        TEST_EQ("TexSamplerBinding", tex_sampler.deco_info.binding, 1, skip);
        TEST_EQ("TexSamplerDescSet", tex_sampler.deco_info.desc_set, 1, skip);

        spv.kill();
        mem_free(pcode, HEAP);
    }
    void Test::Spv::run() {
        TEST_MODULE_BEGIN("SpvTest_1", true, true);

        test_triangle3(SKIP);

        TEST_MODULE_END();
        TEST_MODULE_BEGIN("SpvTest_2", true, false);

        test_triangle3(SKIP);

        TEST_MODULE_END();
    }
} // namespace Sol::Test::SpvTest
