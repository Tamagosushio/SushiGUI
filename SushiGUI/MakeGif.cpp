#include <Siv3D.hpp>
#include "MakeGif.hpp"


/// @brief パラメータの初期化
/// @param path GIFを保存するファイルパス
/// @param fps 30以下でなければならない
MakeGif::MakeGif(const FilePath& path, uint32 fps) : fps(fps) {
  assert(fps <= 30);
  this->refresh_rate = static_cast<uint32>(System::GetCurrentMonitor().refreshRate.value());
  Console << this->refresh_rate;
  writer = AnimatedGIFWriter{ path, Scene::Size() };
}
/// @brief GIFアニメーション作成の起動 
void MakeGif::start(void) {
  this->is_started = true;
}
/// @brief スクリーンショットの撮影、while(System::Update())内で実行する必要がります
void MakeGif::capture(void) {
  if (is_started) {
    ScreenCapture::RequestCurrentFrame();
    ++frame_n %= refresh_rate / fps;
    if (this->frame_n == 0 and ScreenCapture::HasNewFrame()) {
      const Image frame_image = ScreenCapture::GetFrame();
      writer.writeFrame(frame_image, SecondsF(1.0 / this->fps));
    }
  }
}
/// @brief GIFアニメーション作成の終了 
void MakeGif::end(void) {
  writer.close();
  this->is_started = false;
}
