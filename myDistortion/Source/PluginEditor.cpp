/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
MyDistortionAudioProcessorEditor::MyDistortionAudioProcessorEditor (MyDistortionAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (400, 400);
    
    //algorithm selector
    addAndMakeVisible(&disChoice);
    disChoice.addItem("Hard Clip", 1);
    disChoice.addItem("Soft Clip", 2);
    disChoice.addItem("Half-Wave Rect", 3);
    disChoice.setSelectedId(1);
    disChoice.addListener(this);
    
    disChoiceLabel.setText("algorithm", juce::dontSendNotification);
    disChoiceLabel.setFont(juce::Font("Multicolore", 12, 0));
    disChoiceLabel.setColour(juce::Label::textColourId, juce::Colour(255, 255, 255));
    addAndMakeVisible(&disChoiceLabel);
    
    
    //threshold
    Threshold.setSliderStyle(juce::Slider::Rotary);
    Threshold.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 70, 20);
    addAndMakeVisible(&Threshold);
    Threshold.setRange(0.0f, 1.0f, 0.001);
    Threshold.setValue(0.5);
    Threshold.addListener(this);
    
    ThresholdLabel.setText("Threshold", juce::dontSendNotification);
    ThresholdLabel.setFont(juce::Font("Multicolore", 12, 0));
    ThresholdLabel.setColour(juce::Label::textColourId, juce::Colour(255, 255, 255));
    addAndMakeVisible(&ThresholdLabel);
    
    //mix
    Mix.setSliderStyle(juce::Slider::Rotary);
    Mix.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 70, 20);
    addAndMakeVisible(&Mix);
    Mix.setRange(0.0f, 1.0f, 0.001);
    Mix.setValue(0.5);
    Mix.addListener(this);

    MixLabel.setText("Mix", juce::dontSendNotification);
    MixLabel.setFont(juce::Font("Multicolore", 12, 0));
    MixLabel.setColour(juce::Label::textColourId, juce::Colour(255, 255, 255));
    addAndMakeVisible(&MixLabel);
    
    //gain
    Gain.setSliderStyle(juce::Slider::Rotary);
    Gain.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 70, 20);
    addAndMakeVisible(&Gain);
    Gain.setRange(0.0f, 10.0f, 0.001);
    Gain.setValue(1.0);
    Gain.addListener(this);

    GainLabel.setText("Gain", juce::dontSendNotification);
    GainLabel.setFont(juce::Font("Multicolore", 12, 0));
    GainLabel.setColour(juce::Label::textColourId, juce::Colour(255, 255, 255));
    addAndMakeVisible(&GainLabel);
    
    //level
    Level.setSliderStyle(juce::Slider::Rotary);
    Level.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 70, 20);
    addAndMakeVisible(&Level);
    Level.setRange(0.0f, 10.0f, 0.001);
    Level.setValue(1.0);
    Level.addListener(this);

    LevelLabel.setText("Level", juce::dontSendNotification);
    LevelLabel.setFont(juce::Font("Multicolore", 12, 0));
    LevelLabel.setColour(juce::Label::textColourId, juce::Colour(255, 255, 255));
    addAndMakeVisible(&LevelLabel);

}

MyDistortionAudioProcessorEditor::~MyDistortionAudioProcessorEditor()
{
}

//==============================================================================
void MyDistortionAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (juce::Colours::black);

    g.setColour (juce::Colours::white);
    g.setFont (15.0f);
}

void MyDistortionAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    disChoiceLabel.setBounds(50, 20, 200, 20);
    disChoice.setBounds(50, 40, 200, 30);

    ThresholdLabel.setBounds(50, 80, 200, 30);
    Threshold.setBounds(50, 100, 100, 100);

    MixLabel.setBounds(250, 80, 200, 30);
    Mix.setBounds(250, 100, 100, 100);

    GainLabel.setBounds(50, 220, 200, 30);
    Gain.setBounds(50, 240, 100, 100);

    LevelLabel.setBounds(250, 220, 200, 30);
    Level.setBounds(250, 240, 100, 100);
}

void MyDistortionAudioProcessorEditor::comboBoxChanged(juce::ComboBox* comboBoxThatHasChanged)
{
    audioProcessor.menuChoice = comboBoxThatHasChanged->getSelectedId();
}

void MyDistortionAudioProcessorEditor::sliderValueChanged(juce::Slider* slider)
{
    if (&Mix == slider)
    {
        audioProcessor.mix = Mix.getValue();
    }
    if (&Threshold == slider)
    {
        audioProcessor.thresh = Threshold.getValue();
    }
    if (&Gain == slider)
    {
        audioProcessor.gain = Mix.getValue();
    }
    if (&Level == slider)
    {
        audioProcessor.level = Threshold.getValue();
    }

    
}
