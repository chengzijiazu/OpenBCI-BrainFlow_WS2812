#include <Adafruit_NeoPixel.h>

#define PIN            6         // 连接 WS2812B 数据引脚的 Arduino 引脚
#define NUM_PIXELS     64       // 16x16 的 LED 点阵，16 * 16 = 256 个 LED

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_PIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  // 初始化串口通信
  Serial.begin(9600);  // 串口通信速度为 9600
  strip.begin();       // 初始化 LED 灯带
  strip.show();        // 初始化时，关闭所有 LED
}

void loop() {
  // 检查串口是否有数据
  if (Serial.available() > 0) {
    // 读取 RGB 数据
    int r = Serial.parseInt();  // 读取红色通道的值
    int g = Serial.parseInt();  // 读取绿色通道的值
    int b = Serial.parseInt();  // 读取蓝色通道的值

    // 输出接收到的 RGB 值（可用于调试）
    Serial.print("R: ");
    Serial.print(r);
    Serial.print(" G: ");
    Serial.print(g);
    Serial.print(" B: ");
    Serial.println(b);

    // 根据接收到的 RGB 值设置所有 LED 的颜色
    for (int i = 0; i < NUM_PIXELS; i++) {
      strip.setPixelColor(i, strip.Color(r, g, b));
    }

    // 更新 LED 灯带显示
    strip.show();
  }
}
