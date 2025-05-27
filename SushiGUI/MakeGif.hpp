#include <Siv3D.hpp>

/// @brief 実行中のウィンドウのGIFアニメーションを作成する
class MakeGif {
private:
  bool is_started = false;
  uint32 fps = 30;
  uint32 frame_n = 0;
  AnimatedGIFWriter writer;
public:
  // 値初期化
  MakeGif(const FilePath& path, uint32 fps = 30);
  // GIF作成の実行
  void start(void);
  // GIF用スクショの撮影
  void capture(void);
  // GIF作成の終了
  void end(void);
};

