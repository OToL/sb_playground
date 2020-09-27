#include <sb_core/io/virtual_file_system.h>
#include <sb_core/io/file.h>
#include <sb_core/io/path.h>
#include <sb_core/log.h>
#include <sb_core/os.h>

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

  FileHdl file_hdl = VFS::openFileRead("/data/test_file.txt", FileFormat::Text);;
  sbAssert(isValid(file_hdl));
  VFS::closeFile(file_hdl);

  // {
  //     file_hdl = FS::openFileRead("/data/test_file.txt", FileFormat::Text);
  //     File test_file{file_hdl};

  //     ui8 file_data[255] = {};
  //     test_file.read(file_data);
  

  //     sbLogI((char const *)file_data);
  // }

  // // FS::closeFile(file_hdl);

   VFS::terminate();

  return 0;
}
