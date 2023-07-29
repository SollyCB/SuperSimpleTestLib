#include "test.hpp"
#include "spv_test.hpp"
#include "Spv.hpp"
#include "File.hpp"
#include "Allocator.hpp"
#include <cstdint>
#include <cstddef>

namespace Sol::Test::SpvTest {
    static const bool SKIP = false;
    static Allocator *HEAP = &MemoryService::instance()->system_allocator;

    void test_triangle3(bool skip) {
        TEST_FUNC_BEGIN();

        size_t code_size = 0;
        const uint32_t *pcode = File::read_spv(&code_size, "triangle3.vert.spv", HEAP);
        Spv spv = Spv::parse(code_size, pcode);

        using Flags = Spv::DecoFlagBits;

        Spv::Var ubo = *(reinterpret_cast<Spv::Var*>(spv.types[2].data));
        uint32_t deco_flags_binding = static_cast<uint32_t>(Flags::BINDING);
        uint32_t deco_flags_desc_set = static_cast<uint32_t>(Flags::DESC_SET);
        TEST_EQ(ubo.deco_info.flags, deco_flags_binding | deco_flags_desc_set, true, skip);

        Spv::Var in_color = *(reinterpret_cast<Spv::Var*>(spv.types[5].data));
        uint32_t deco_flags_location = static_cast<uint32_t>(Flags::LOCATION);
        TEST_EQ(in_color.deco_info.flags, deco_flags_location, true, skip);
        TEST_EQ(in_color.deco_info.location, 1, true, skip);

        Spv::Var tex_sampler = *(reinterpret_cast<Spv::Var*>(spv.types[6].data));
        TEST_EQ(tex_sampler.deco_info.flags, deco_flags_binding | deco_flags_desc_set, true, skip);
        TEST_EQ(tex_sampler.deco_info.binding, 1, true, skip);
        TEST_EQ(tex_sampler.deco_info.desc_set, 1, true, skip);

        spv.kill();
        mem_free(pcode, HEAP);
        TEST_FUNC_END();
    }
    void run() {
        TEST_PRINT_BEGIN();
        test_triangle3(SKIP);
    }
} // namespace Sol::Test::SpvTest
