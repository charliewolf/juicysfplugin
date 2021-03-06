/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "FluidSynthModel.h"
#include "StateChangeSubscriber.h"
#include "SharesParams.h"
#include <list>

using namespace std;

//==============================================================================
/**
*/
class JuicySFAudioProcessor  : public AudioProcessor,
                               public SharesParams
{
public:
    //==============================================================================
    JuicySFAudioProcessor();
    ~JuicySFAudioProcessor();

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

    void processBlock (AudioBuffer<float>& buffer, MidiBuffer& midiMessages) override;

    //==============================================================================
    AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const String getProgramName (int index) override;
    void changeProgramName (int index, const String& newName) override;

    //==============================================================================
    void getStateInformation (MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;

    bool supportsDoublePrecisionProcessing() const override;

    FluidSynthModel* getFluidSynthModel();

    MidiKeyboardState keyboardState;

    virtual void setSoundFontPath(const String& value) override;
    virtual String& getSoundFontPath() override;
    virtual int getPreset() override;
    virtual void setPreset(int preset) override;
    virtual int getBank() override;
    virtual void setBank(int bank) override;

//    void subscribeToStateChanges(StateChangeSubscriber* subscriber);
//    void unsubscribeFromStateChanges(StateChangeSubscriber* subscriber);

    int lastUIWidth, lastUIHeight;

private:
    void initialiseSynth();

    String soundFontPath;
    int lastPreset;
    int lastBank;

    FluidSynthModel fluidSynthModel;
    fluid_synth_t* fluidSynth;
    Synthesiser synth;

//    // just a raw pointer; we do not own
//    AudioProcessorEditor* pluginEditor;

//    list<StateChangeSubscriber*> stateChangeSubscribers;

    static BusesProperties getBusesProperties();

//    Model* model;
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (JuicySFAudioProcessor)
};
