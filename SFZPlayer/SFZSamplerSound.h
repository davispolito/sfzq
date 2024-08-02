//
// Created by Davis Polito on 8/2/24.
//

#ifndef SFZPLAYER_SFZSAMPLERSOUND_H
#define SFZPLAYER_SFZSAMPLERSOUND_H




class SFZSamplerSound : public SamplerSound
{
public:
    SFZSamplerSound(const String& name, const String& path)
            : name(name), impl(std::make_unique<SFZSound>(path))
    {
        // Any additional initialization
    }

    ~SFZSamplerSound() override = default;

    const String& getName() const noexcept override
            {
                    return name;
            }

    AudioBuffer<float>* getAudioData() const noexcept override
            {
                    return impl->getAudioData();
            }

    void setEnvelopeParameters(ADSR::Parameters parametersToUse) override
    {
        impl->setEnvelopeParameters(parametersToUse);
    }

    bool appliesToNote(int midiNoteNumber) override
    {
        return impl->appliesToNote(midiNoteNumber);
    }

    bool appliesToChannel(int midiChannel) override
    {
        return impl->appliesToChannel(midiChannel);
    }

    // Optionally, you can provide additional methods to interact with SFZSound
    void loadRegions() { impl->loadRegions(); }
    void loadSamples(std::function<void(double)> progress_fn = {}) { impl->loadSamples(progress_fn); }
    // Add other methods that may be useful

private:
    String name;
    std::unique_ptr<SFZSound> impl;  // Holds the concrete implementation
};


#endif //SFZPLAYER_SFZSAMPLERSOUND_H
