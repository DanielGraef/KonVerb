/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic startup code for a Juce application.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"


//==============================================================================
KonVerbAudioProcessor::KonVerbAudioProcessor()
{
    UserParams[Volume]=1.0f;//default Width 1.0 (no change)
    mKonVerb.setVolume(UserParams[Volume]);//push VST default to effect
    UIUpdateFlag=true;//Request UI update
}

KonVerbAudioProcessor::~KonVerbAudioProcessor()
{
}

//==============================================================================
const String KonVerbAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

int KonVerbAudioProcessor::getNumParameters()
{
    return totalNumParam;
}

float KonVerbAudioProcessor::getParameter (int index)
{
    switch(index)
    {
    case Volume://example update from internal
        UserParams[Volume]=mKonVerb.getVolume();
        return UserParams[Volume];
    default: return 0.0f;//invalid index
    }
}

void KonVerbAudioProcessor::setParameter (int index, float newValue)
{
    switch(index)
    {
    case Volume:
        UserParams[Volume]=newValue;
        mKonVerb.setVolume(UserParams[Volume]);
        break;
    default: return;
    }
}

const String KonVerbAudioProcessor::getParameterName (int index)
{
    switch(index)
    {
    case Volume: return "Volume Factor";
    default:return String::empty;
    }
}

const String KonVerbAudioProcessor::getParameterText (int index)
{
    if(index>=0 && index<totalNumParam)
        return String(UserParams[index]);//return parameter value as string
    else return String::empty;
}

const String KonVerbAudioProcessor::getInputChannelName (int channelIndex) const
{
    return String (channelIndex + 1);
}

const String KonVerbAudioProcessor::getOutputChannelName (int channelIndex) const
{
    return String (channelIndex + 1);
}

bool KonVerbAudioProcessor::isInputChannelStereoPair (int index) const
{
    return true;
}

bool KonVerbAudioProcessor::isOutputChannelStereoPair (int index) const
{
    return true;
}

bool KonVerbAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool KonVerbAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool KonVerbAudioProcessor::silenceInProducesSilenceOut() const
{
    return false;
}

double KonVerbAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int KonVerbAudioProcessor::getNumPrograms()
{
    return 0;
}

int KonVerbAudioProcessor::getCurrentProgram()
{
    return 0;
}

void KonVerbAudioProcessor::setCurrentProgram (int index)
{
}

const String KonVerbAudioProcessor::getProgramName (int index)
{
    return String::empty;
}

void KonVerbAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void KonVerbAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
}

void KonVerbAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

void KonVerbAudioProcessor::processBlock (AudioSampleBuffer& buffer, MidiBuffer& midiMessages)
{
    // This is the place where you'd normally do the guts of your plugin's
    // audio processing...
    if( !(getNumInputChannels()<2) ) {
        for (int channel = 0; channel < getNumInputChannels(); ++channel) {
            float* channelData = buffer.getWritePointer (channel);
            // ..do something to the data...
            for(long i=0; i < buffer.getNumSamples(); i++)
                mKonVerb.clockProcess(&channelData[i]);
        }
    }

    // // In case we have more outputs than inputs, we'll clear any output
    // // channels that didn't contain input data, (because these aren't
    // // guaranteed to be empty - they may contain garbage).
    // for (int i = getNumInputChannels(); i < getNumOutputChannels(); ++i)
    // {
    //     buffer.clear (i, 0, buffer.getNumSamples());
    // }

}

//==============================================================================
bool KonVerbAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* KonVerbAudioProcessor::createEditor()
{
    return new KonVerbAudioProcessorEditor (this);
}

//==============================================================================
void KonVerbAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
    XmlElement root("Root");
    XmlElement *el;
    el = root.createNewChildElement("Volume");
    el->addTextElement(String(UserParams[Volume]));
    copyXmlToBinary(root,destData);
}

void KonVerbAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
    XmlElement* pRoot = getXmlFromBinary(data,sizeInBytes);
    if(pRoot!=NULL)
    {
        forEachXmlChildElement((*pRoot),pChild)
        {
            if(pChild->hasTagName("Volume"))
            {String text = pChild->getAllSubText();
            setParameter(Volume,text.getFloatValue());}
        }
        delete pRoot;
        UIUpdateFlag=true;//Request UI update
    }
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new KonVerbAudioProcessor();
}
