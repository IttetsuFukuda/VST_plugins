/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class MyDistortionAudioProcessorEditor  : public juce::AudioProcessorEditor,
private juce::ComboBox::Listener, juce::Slider::Listener
{
public:
    MyDistortionAudioProcessorEditor (MyDistortionAudioProcessor&);
    ~MyDistortionAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    void comboBoxChanged(juce::ComboBox* comboBoxThatHasChanged) override;
    
    void sliderValueChanged(juce::Slider* sliderThatHasChanged) override;
    
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    MyDistortionAudioProcessor& audioProcessor;

    juce::ComboBox disChoice;
    juce::Label disChoiceLabel;
    
    juce::Slider Threshold;
    juce::Label ThresholdLabel;
    
    juce::Slider Mix;
    juce::Label MixLabel;
    
    juce::Slider Gain;
    juce::Label GainLabel;
    
    juce::Slider Level;
    juce::Label LevelLabel;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MyDistortionAudioProcessorEditor)
};
