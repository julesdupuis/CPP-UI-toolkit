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
#include <iostream>
#include <raylib.h>
#include <sstream>
#include <string>

int main(void){
    BorderLayout borderLayout(true);
    Window window(borderLayout);
    window.setTitle("Test Event-based API");

    Player player;
    PlayerListener playerListener(player);

    TextModel playerPosText("0, 0");
    Label playerPosLabel(playerPosText);

    float runTime = 0;
    TextModel runTimeText(std::to_string(runTime));
    runTimeText.setFontSize(20);
    Label runTimeLabel(runTimeText);
    Label runTimeLabel2(runTimeText);

    FrameListener runTimeListener([&runTime, &runTimeText](){
        runTime += GetFrameTime();
        runTimeText.setText(std::to_string(runTime));
    });

    BoundedRangeModel rangeModel;
    rangeModel.setMinValue(-30);
    rangeModel.setMaxValue(70);
    rangeModel.setCurrentValue(30);

    InputListener rangePrinter([](){
        return IsKeyReleased(KeyboardKey::KEY_R);
    },
    [&rangeModel](){
        rangeModel.toStr(std::cerr);
        std::cerr<<"\n";
    });

    std::ostringstream rangeStrStream;
    rangeModel.toStr(rangeStrStream);
    TextModel rangeText(rangeStrStream.str());
    rangeText.setFontSize(20);
    Label rangeLabel(rangeText);

    Listener rangeLabelListener([&rangeModel, &rangeText](){
        std::ostringstream rangeStrStream;
        rangeModel.toStr(rangeStrStream);
        rangeText.setText(rangeStrStream.str());
    });
    rangeModel.subscribe(rangeLabelListener);

    InputListener layoutDebugPrinter([](){
        return IsKeyReleased(KeyboardKey::KEY_L);
    },
    [&window](){
        std::cerr<<window<<"\n";
    });

    Slider slider(rangeModel);

    StackLayout topPanelLayout(false);
    Panel topPanel(topPanelLayout);
    topPanel.setBackgroundColor(GRAY);
    topPanel.add(runTimeLabel2, StackLayout::Constraints::LAST);
    topPanel.add(playerPosLabel, StackLayout::Constraints::LAST);
    topPanel.add(slider, StackLayout::Constraints::LAST);
    topPanel.add(rangeLabel, StackLayout::Constraints::LAST);

    BorderLayout buttonPanelLayout;
    Panel buttonPanel(buttonPanelLayout);
    buttonPanel.setBackgroundColor(GRAY);

    ButtonModel dummyButtonModel;

    TextModel testButtonText("test button");
    Label testButtonLabel(testButtonText);
    Button testButton(dummyButtonModel);
    testButton.add(testButtonLabel);

    TextModel clickButtonText("CLICK");
    Label clickButtonLabel(clickButtonText);
    Button buttonClick(dummyButtonModel);
    buttonClick.add(clickButtonLabel);

    TextModel statusText("HELLO WORLD");
    statusText.setFontSize(20);
    Label statusLabel(statusText);

    Label statusLabel2(statusText);

    TextModel specialButtonText("I AM SPECIAL");
    Label specialButtonLabel(specialButtonText);
    Button specialButton(dummyButtonModel);
    specialButton.add(specialButtonLabel);

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
    buttonPanel.add(testButton, BorderLayout::Constraints::RIGHT);
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

    Label smallLabel1(statusText);
    Label smallLabel2(statusText);
    Label smallLabel3(statusText);

    Box middleBox;
    middleBox.add(smallLabel2);
    middleBox.SetBackgroundColor(PURPLE);
    middleBox.setInsets({5, 10, 0, 0});

    StackLayout smallStacklayout;
    Panel smallPanel(smallStacklayout);
    smallPanel.setBackgroundColor(PINK);
    smallPanel.add(smallLabel1, StackLayout::Constraints::LAST);
    smallPanel.add(middleBox, StackLayout::Constraints::LAST);
    smallPanel.add(smallLabel3, StackLayout::Constraints::LAST);

    BorderLayout centerBl2(true);
    Container centerPanel2(centerBl2);
    centerPanel2.add(smallPanel, BorderLayout::Constraints::BOTTOM);
    centerPanel2.add(centerPanel, BorderLayout::Constraints::CENTER);

    BorderLayout centerBL;
    Panel centerPanelSides(centerBL);
    centerPanelSides.setBackgroundColor(BLANK);

    Slider sideSlider(rangeModel);
    sideSlider.setVertical(true);

    centerPanelSides.add(centerPanel2, BorderLayout::Constraints::CENTER);
    centerPanelSides.add(sideSlider, BorderLayout::Constraints::RIGHT);

    window.add(topPanel, BorderLayout::Constraints::LEFT);
    window.add(centerPanelSides, BorderLayout::Constraints::CENTER);
    window.add(buttonPanel, BorderLayout::Constraints::RIGHT);

    window.run();

    rangeModel.unsubscribe(rangeLabelListener);

    // FUNCTIONNALITY
    // TODO timer
    // TODO scrollPane
    // TODO list
    // TODO split pane
    // TODO progress bar
    // TODO combo box
    // TODO radio button group
    // TODO tabbed panel

    // TODO MAYBE window destroy listener

    // TODO component renderers

    // ACCESSIBILTY
    // TODO translatable string
    // TODO action search bar
    // TODO key mapping
    // TODO config menu
    // TODO color vision handling
    // TODO narrator
    // TODO extreme sound user parametrisation

    // DEMO
    // TODO draw player
    // TODO draw player pos label

    // BUG MAYBE Button is pressed on click outside then hover inside

    return 0;
}
