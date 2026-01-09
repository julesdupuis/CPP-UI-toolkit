#include "component/button.hpp"
#include "component/container.hpp"
#include "component/label.hpp"
#include "component/panel.hpp"
#include "component/window.hpp"
#include "event/frameListener.hpp"
#include "layout/borderLayout.hpp"
#include "layout/layeredLayout.hpp"
#include "layout/stackLayout.hpp"
#include "player.hpp"
#include "model/textModel.hpp"
#include <raylib.h>
#include <string>

int main(void){
    BorderLayout borderLayout(true);
    Window window(borderLayout);
    window.setTitle("Test Event-based API");

    Player player;
    PlayerListener playerListener(player);

    TextModel playerPosText("0, 0");
    Label playerPosLabel(playerPosText);
    playerPosLabel.fit();

    float runTime = 0;
    TextModel runTimeText(std::to_string(runTime));
    runTimeText.setFontSize(20);
    Label runTimeLabel(runTimeText);
    runTimeLabel.fit();
    Label runTimeLabel2(runTimeText);
    runTimeLabel2.fit();

    FrameListener runTimeListener([&runTime, &runTimeText](){
        runTime += GetFrameTime();
        runTimeText.setText(std::to_string(runTime));
    });

    StackLayout stackLayout(false);
    Panel container(stackLayout);
    container.setBackgroundColor(GRAY);
    container.add(runTimeLabel2, static_cast<int>(StackLayout::Constraints::LAST));
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

    TextModel statusText("HELLO WORLD");
    statusText.setFontSize(20);
    Label statusLabel(statusText);
    statusLabel.fit();

    Label statusLabel2(statusText);
    statusLabel2.fit();

    Button specialButton;
    specialButton.setText("I AM SPECIAL");
    specialButton.fit();

    StackLayout statusLayout(false);
    Panel statusPanel(statusLayout);
    statusPanel.setBackgroundColor(BLUE);
    statusPanel.add(statusLabel, static_cast<int>(StackLayout::Constraints::LAST));
    statusPanel.add(specialButton, static_cast<int>(StackLayout::Constraints::LAST));
    statusPanel.add(statusLabel2, static_cast<int>(StackLayout::Constraints::LAST));

    buttonPanel.add(buttonClick, static_cast<int>(BorderLayout::Constraints::LEFT));
    buttonPanel.add(button, static_cast<int>(BorderLayout::Constraints::RIGHT));
    buttonPanel.add(statusPanel, static_cast<int>(BorderLayout::Constraints::CENTER));

    LayeredLayout centerLayout;
    Container centerPanel(centerLayout);

    TextModel feur1("FEUR");
    feur1.setFontSize(300);
    feur1.setColor(BLUE);
    feur1.setSpacing(10);

    TextModel feur2("FEUR");
    feur2.setFontSize(200);
    feur2.setColor(YELLOW);
    feur2.setSpacing(5);

    TextModel feur3("FEUR");
    feur3.setFontSize(100);
    feur3.setColor(RED);

    Label feur1Label(feur1);
    Label feur2Label(feur2);
    Label feur3Label(feur3);

    centerPanel.add(feur1Label, static_cast<int>(LayeredLayout::Constraints::FRONT));
    centerPanel.add(feur2Label, static_cast<int>(LayeredLayout::Constraints::FRONT));
    centerPanel.add(feur3Label, static_cast<int>(LayeredLayout::Constraints::FRONT));
    centerPanel.add(runTimeLabel, static_cast<int>(LayeredLayout::Constraints::FRONT));

    window.add(container, static_cast<int>(BorderLayout::Constraints::LEFT));
    window.add(centerPanel, static_cast<int>(BorderLayout::Constraints::CENTER));
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

    // TODO FIX Button is pressed on click outside then hover inside

    return 0;
}
