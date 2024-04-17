#include <Novice.h>
#include<Vector3.h>
#define _USE_MATH_DEFINES
#include<math.h>

//加算
Vector3 Add(const Vector3& v1, const Vector3& v2) {
	Vector3 v3 = {};
	v3.x = v1.x + v2.x;
	v3.y = v1.y + v2.y;
	v3.z = v1.z + v2.z;
	return v3;
}
//減算
Vector3 Subtract(const Vector3& v1, const Vector3& v2) {
	Vector3 v3 = {};
	v3.x = v1.x - v2.x;
	v3.y = v1.y - v2.y;
	v3.z = v1.z - v2.z;
	return v3;
}
//スカラー
Vector3 Multiply(float scalar, const Vector3& v) {
	Vector3 v2 = {};
	v2.x = v.x * scalar;
	v2.y = v.y * scalar;
	v2.z = v.z * scalar;
	return v2;
}
//内積
float Dot(const Vector3& v1, const Vector3& v2) {
	float dot = {};
	dot = v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
	return dot;
}
//長さ
float Length(const Vector3& v) {
	float len = {};
	len = sqrtf(Dot(v, v));
	return len;

}
//正規化
Vector3 Normalize(const Vector3& v) {
	float len = Length(v);
	Vector3 v2 = {};
	v2.x = v.x / len;
	v2.y = v.y / len;
	v2.z = v.z / len;

	return v2;
}

static const int kColumnWidth = 60;

void VectorScreenPrintf(int x, int y, const Vector3& vector, const char* label) {

	Novice::ScreenPrintf(x, y, "%.02f", vector.x);
	Novice::ScreenPrintf(x + kColumnWidth, y, "%.02f", vector.y);
	Novice::ScreenPrintf(x + kColumnWidth*2, y, "%.02f", vector.z);
	Novice::ScreenPrintf(x + kColumnWidth*3, y, "%s", label);
}
const char kWindowTitle[] = "LE2B_15_MT3_01_Vector3";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	Vector3 v1={ 1.0f,3.0f,-5.0f };
	Vector3 v2={ 4.0f,-1.0f,2.0f };
	float k = 4.0f;

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///
		Vector3 resultAdd = Add(v1, v2);
		Vector3 resultSubtract = Subtract(v1, v2);
		Vector3 resultMultiply = Multiply(k, v1);
		float resultDot = Dot(v1, v2);
		float resultLength = Length(v1);
		Vector3 resultNormalize = Normalize(v2);


		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		VectorScreenPrintf(0, 0, resultAdd, " :Add");
		VectorScreenPrintf(0,20,resultSubtract," : Subtract");
		VectorScreenPrintf(0, 20*2, resultMultiply, " : Subtract");
		Novice::ScreenPrintf(0, 20 * 3, "%.02f : Dot", resultDot);
		Novice::ScreenPrintf(0, 20 * 4, "%.02f : Length", resultLength);
		VectorScreenPrintf(0, 20 * 5, resultNormalize, " : Normalize");
	   
		
		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
