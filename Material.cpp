#pragma once
#include <string>
#include "Exception.cpp"

class MediaFile {
protected:
    int id;
    std::string name;
    double fileSizeMb;
    double bitrate;
    std::string creatorName;
public:
    MediaFile(int i, const std::string& n, double q, double p, const std::string& s = "Unknown")
        : id(i), name(n), fileSizeMb(q), bitrate(p), creatorName(s) {
    }
    virtual ~MediaFile() = default;

    double calculateCost(double amount) const {
        if (amount <= 0) throw ContentNotFoundException("amount <= 0");
        return amount * bitrate;
    }
    void consume(double amount) {
        if (amount > fileSizeMb) throw StorageLimitException(name);
        fileSizeMb -= amount;
    }
    void restock(double amount) { fileSizeMb += amount; }
    bool isAvailable(double amount) const { return fileSizeMb >= amount; }
};

class VideoFile : public MediaFile {
    int resolution;
    double duration;
public:
    VideoFile(int i, double q, int r, double d) : MediaFile(i, "Video", q, 1.2), resolution(r), duration(d) {}
    bool isHD() const { return resolution >= 1080; }
};

class ImageFile : public MediaFile {
    int megapixels;
    bool rawFormat;
public:
    ImageFile(int i, double q, int mp, bool raw) : MediaFile(i, "Image", q, 2.5), megapixels(mp), rawFormat(raw) {}
    bool isProQuality() const { return megapixels > 20; }
};

class AudioFile : public MediaFile {
    double sampleRate;
    bool lossless;
public:
    AudioFile(int i, double q, double sr, bool ll) : MediaFile(i, "Audio", q, 1.5), sampleRate(sr), lossless(ll) {}
    bool isStudioQuality() const { return sampleRate > 44.1 && lossless; }
};