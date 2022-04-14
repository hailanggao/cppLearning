#include <iostream>

struct Vertex {

	float x, y, z;
};
int main() {
	Log log;
	log.SetLevel(Log::LevelWarning);
	log.Info("Hello");
	log.Error("Hello");
	log.Warn("Hello");
	std::cin.get();
}