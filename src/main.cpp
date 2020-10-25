#include <sb_core/io/virtual_file_system.h>
#include <sb_core/io/file_stream.h>
#include <sb_core/io/path.h>
#include <sb_core/log.h>
#include <sb_core/os.h>
#include <sb_core/enum.h>
#include <sb_core/memory/alloc.h>

#include <sb_std/xutility>

int main()
{
  using namespace sb;

  char local_data_dir[LOCAL_PATH_MAX_LEN];
  getWorkingDirectory(local_data_dir);

  concatLocalPath(local_data_dir, "data");

  VFS::InitDesc vfs_desc = {};

  VFS::LayerInitDesc phys_layers[] = 
  {
    {
      "data"_hs,
      "/data/",
      sbstd::data(local_data_dir)
    }
  };
  vfs_desc.layers = phys_layers;

  b8 const vfs_init_res = VFS::initialize(vfs_desc);
  sbAssert(vfs_init_res, "Failed to initialize VFS");

  sbAssert(VFS::fileExists("/data/test_file.txt"));

  {
    FileStream file(VFS::openFileRead("/data/test_file.txt", FileFormat::TEXT));
    sbAssert(file.isValid());

    u8 value[255];
    file.read(value);

    // file.write({(u8 const *)"Manu", 5});
    file.read(value);
  }

   VFS::terminate();

  return 0;
}
