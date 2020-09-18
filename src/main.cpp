#include <sb_core/io/file_system.h>
#include <sb_core/io/file.h>
#include <sb_core/log.h>

using namespace sb;

int main()
{
    // FileSystem::InitParams fs_params;

    // FS::LayerDesc phys_layers[1];

    // phys_layers[0].m_logical_path = "/data/";
    // phys_layers[0].m_physical_path = "/Users/ebeau/Documents/dev/perso/sb_basic/data/";
    // phys_layers[0].m_name = HashStr("data");

    // fs_params.m_layers = Span<FS::LayerDesc>{phys_layers};

    // FS::initialize(fs_params);

    // FileHdl file_hdl;

    // {
    //     file_hdl = FS::openFileRead("/data/test_file.txt", FileFormat::Text);
    //     File test_file{file_hdl};

    //     ui8 file_data[255] = {};
    //     test_file.read(file_data);

    //     sbLogI((char const *)file_data);
    // }

    // // FS::closeFile(file_hdl);

    // FS::terminate();

    return 0;
}
