#include <visualizer/game_of_life_app.h>

using gameoflife::visualizer::GameOfLifeApp;

void prepareSettings(GameOfLifeApp::Settings* settings) {
  settings->setResizable(false);
}

// This line is a macro that expands into an "int main()" function.
CINDER_APP(GameOfLifeApp, ci::app::RendererGl, prepareSettings);
