/*
  ==============================================================================

  This is an automatically generated GUI class created by the Introjucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Introjucer version: 3.1.0

  ------------------------------------------------------------------------------

  The Introjucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright 2004-13 by Raw Material Software Ltd.

  ==============================================================================
*/

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "PluginEditor.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
KonVerbAudioProcessorEditor::KonVerbAudioProcessorEditor (KonVerbAudioProcessor* ownerFilter)
    : AudioProcessorEditor(ownerFilter)
{
    addAndMakeVisible (VolumeSld = new Slider ("Volume Slider"));
    VolumeSld->setRange (0, 1, 0.01);
    VolumeSld->setSliderStyle (Slider::LinearHorizontal);
    VolumeSld->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    VolumeSld->addListener (this);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
    getProcessor()->RequestUIUpdate();// UI update must be done each time a new editor is constructed
    startTimer(200);
    //[/Constructor]
}

KonVerbAudioProcessorEditor::~KonVerbAudioProcessorEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    VolumeSld = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void KonVerbAudioProcessorEditor::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colours::black);

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void KonVerbAudioProcessorEditor::resized()
{
    VolumeSld->setBounds (16, 8, 344, 24);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void KonVerbAudioProcessorEditor::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    KonVerbAudioProcessor* ourProcessor = getProcessor();
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == VolumeSld)
    {
        //[UserSliderCode_VolumeSld] -- add your slider handling code here..
      ourProcessor->setParameter(KonVerbAudioProcessor::Volume, (float)VolumeSld->getValue());
        //[/UserSliderCode_VolumeSld]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void KonVerbAudioProcessorEditor::timerCallback()
{
  KonVerbAudioProcessor* ourProcessor = getProcessor();
  //exchange any data you want between UI elements and the Plugin "ourProcessor"
  if(ourProcessor->NeedsUIUpdate())
  {
    VolumeSld->setValue(ourProcessor->getParameter(KonVerbAudioProcessor::Volume), juce::dontSendNotification);
    ourProcessor->ClearUIUpdateFlag();
  }
}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Introjucer information section --

    This is where the Introjucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="KonVerbAudioProcessorEditor"
                 componentName="" parentClasses="public AudioProcessorEditor, public Timer"
                 constructorParams="KonVerbAudioProcessor* ownerFilter" variableInitialisers="AudioProcessorEditor(ownerFilter)"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="ff000000"/>
  <SLIDER name="Volume Slider" id="9d11262a1b5a85f5" memberName="VolumeSld"
          virtualName="" explicitFocusOrder="0" pos="16 8 344 24" min="0"
          max="1" int="0.010000000000000000208" style="LinearHorizontal"
          textBoxPos="TextBoxLeft" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
