#include "../component/box.hpp"
#include "../component/button.hpp"
#include "../component/container.hpp"
#include "../component/fpsLabel.hpp"
#include "../component/label.hpp"
#include "../component/panel.hpp"
#include "../component/slider.hpp"
#include "../component/window.hpp"
#include "../event/frameListener.hpp"
#include "../event/inputListener.hpp"
#include "../layout/borderLayout.hpp"
#include "../layout/layeredLayout.hpp"
#include "../layout/stackLayout.hpp"
#include "../model/boundedRangeModel.hpp"
#include "../model/textModel.hpp"
#include "player.hpp"
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

    BoundedRangeModel rangeModel;
    Slider slider(rangeModel);
    slider.setSize({100, 30});
    rangeModel.setCurrentValue(70);

    StackLayout topPanelLayout(false);
    Panel topPanel(topPanelLayout);
    topPanel.setBackgroundColor(GRAY);
    topPanel.add(runTimeLabel2, StackLayout::Constraints::LAST);
    topPanel.add(playerPosLabel, StackLayout::Constraints::LAST);
    topPanel.add(slider, StackLayout::Constraints::LAST);

    BorderLayout buttonPanelLayout;
    Panel buttonPanel(buttonPanelLayout);
    buttonPanel.setBackgroundColor(GRAY);

    Action dummyAction;

    Button button(dummyAction);
    button.setText("test button");
    button.fit();

    Button buttonClick(dummyAction);
    buttonClick.setText("CLICK");
    buttonClick.setSize({50, 50});

    TextModel statusText("HELLO WORLD");
    statusText.setFontSize(20);
    Label statusLabel(statusText);
    statusLabel.fit();

    Label statusLabel2(statusText);
    statusLabel2.fit();

    Button specialButton(dummyAction);
    specialButton.setText("I AM SPECIAL");
    specialButton.fit();

    FPSLabel fpsLabel;
    InputListener fpsShowing([](){
        return IsKeyReleased(KeyboardKey::KEY_F);
    },
    [&fpsLabel](){
        if(fpsLabel.isShown()){
            fpsLabel.show(false);
        }else{
            fpsLabel.show(true);
        }
    });

    Box fpsBox;
    fpsBox.add(fpsLabel);
    fpsBox.setInsets({10, 10, 10, 10});
    fpsBox.SetBackgroundColor(DARKBROWN);

    StackLayout statusLayout(false);
    Panel statusPanel(statusLayout);
    statusPanel.setBackgroundColor(BLUE);
    statusPanel.add(statusLabel, StackLayout::Constraints::LAST);
    statusPanel.add(specialButton, StackLayout::Constraints::LAST);
    statusPanel.add(statusLabel2, StackLayout::Constraints::LAST);
    statusPanel.add(fpsBox, StackLayout::Constraints::LAST);

    buttonPanel.add(buttonClick, BorderLayout::Constraints::LEFT);
    buttonPanel.add(button, BorderLayout::Constraints::RIGHT);
    buttonPanel.add(statusPanel, BorderLayout::Constraints::CENTER);

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

    centerPanel.add(feur1Label, LayeredLayout::Constraints::FRONT);
    centerPanel.add(feur2Label, LayeredLayout::Constraints::FRONT);
    centerPanel.add(feur3Label, LayeredLayout::Constraints::FRONT);
    centerPanel.add(runTimeLabel, LayeredLayout::Constraints::FRONT);

    BorderLayout centerBL;
    Panel centerPanelSides(centerBL);
    centerPanelSides.setBackgroundColor(BLANK);

    Slider sideSlider(rangeModel);
    sideSlider.setVertical(true);

    centerPanelSides.add(centerPanel, BorderLayout::Constraints::CENTER);
    centerPanelSides.add(sideSlider, BorderLayout::Constraints::RIGHT);

    window.add(topPanel, BorderLayout::Constraints::LEFT);
    window.add(centerPanelSides, BorderLayout::Constraints::CENTER);
    window.add(buttonPanel, BorderLayout::Constraints::RIGHT);

    window.run();

    // FUNCTIONNALITY
    // TODO timer
    // TODO slider
    // TODO scrollPane
    // TODO list
    // TODO split pane

    // ACCESSIBILTY
    // TODO translatable string
    // TODO action search bar
    // TODO key mapping
    // TODO config menu
    // TODO color vision handling
    // TODO narrator

    // DEMO
    // TODO draw player
    // TODO draw player pos label

    // BUG MAYBE Button is pressed on click outside then hover inside

    return 0;
}
