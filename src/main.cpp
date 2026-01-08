#include "component/button.hpp"
#include "component/label.hpp"
#include "component/panel.hpp"
#include "component/window.hpp"
#include "event/frameListener.hpp"
#include "layout/borderLayout.hpp"
#include "layout/stackLayout.hpp"
#include "player.hpp"
#include "model/textModel.hpp"
#include <raylib.h>
#include <string>

int main(void){
    BorderLayout borderLayout(true);
    Window window(borderLayout);

    Player player;
    PlayerListener playerListener(player);

    TextModel playerPosText("0, 0");
    Label playerPosLabel(playerPosText);

    float runTime = 0;
    TextModel runTimeText;
    runTimeText.setFontSize(20);
    Label runTimeLabel(runTimeText);

    FrameListener runTimeListener([&runTime, &runTimeLabel](){
        runTime += GetFrameTime();
        runTimeLabel.getTextModel().setText(std::to_string(runTime));
        runTimeLabel.fit();
    });

    StackLayout stackLayout(false);
    Panel container(stackLayout);
    container.setBackgroundColor(GRAY);
    container.add(runTimeLabel, static_cast<int>(StackLayout::Constraints::LAST));
    container.add(playerPosLabel, static_cast<int>(StackLayout::Constraints::LAST));

    BorderLayout buttonPanelLayout;
    Panel buttonPanel(buttonPanelLayout);
    buttonPanel.setBackgroundColor(GRAY);

    Button button;
    button.setText("test button");
    button.fit();

    Button buttonClick;
    buttonClick.setText("CLICK");
    buttonClick.setSize({50, 50});

    buttonPanel.add(buttonClick, static_cast<int>(BorderLayout::Constraints::LEFT));
    buttonPanel.add(button, static_cast<int>(BorderLayout::Constraints::RIGHT));

    window.add(container, static_cast<int>(BorderLayout::Constraints::LEFT));
    window.add(runTimeLabel, static_cast<int>(BorderLayout::Constraints::CENTER));
    window.add(buttonPanel, static_cast<int>(BorderLayout::Constraints::RIGHT));

    window.run();

    // TODO timer
    // TODO slider
    // TODO scrollPane
    // TODO layeredLayout
    // TODO freeLayout
    // TODO list
    // TODO fpsLabel

    // TODO draw player
    // TODO draw player pos label

    return 0;
}
