#ifndef GRAPHICAL_FILE_FORMATS_H
#define GRAPHICAL_FILE_FORMATS_H

#include <iostream>
#include <string>
#include <iomanip>

class Graphical_File {
public:
    std::string FILE_NAME;

    Graphical_File() = default;
    Graphical_File(std::string fn, unsigned bd, std::size_t h, std::size_t w) :
        FILE_NAME(fn), BITDEPTH(bd), H_PIXELS(h), W_PIXELS(w) { MB = calculate_mb(); };
    virtual ~Graphical_File() = default;

    virtual void print(std::ostream&) const;
    void crop(std::size_t, std::size_t);
    double calculate_mb();
protected:
    double MB = 0.0;
private:
    unsigned BITDEPTH = 0;
    std::size_t H_PIXELS = 0;
    std::size_t W_PIXELS = 0;
};

class JPEG : public Graphical_File {
public:
    JPEG() = default;
    JPEG(std::string fn, unsigned bd, std::size_t h, std::size_t w, double c) :
        Graphical_File(fn, bd, h, w), COMPRESSION(c) { };

    void print(std::ostream&) const override;
private: 
    double COMPRESSION = 0.0;
    const std::string TYPE = "JPEG";
};

class TIFF : public Graphical_File {
public:
    TIFF() = default;
    TIFF(std::string fn, unsigned bd, std::size_t h, std::size_t w, std::string c) :
        Graphical_File(fn, bd, h, w), COMPRESSION_TAG(c) { };
    
    void print(std::ostream&) const override;
private: 
    std::string COMPRESSION_TAG = "";
    const std::string TYPE = "TIFF";
};

class GIF : public Graphical_File {
public:
    GIF() = default;
    GIF(std::string fn, unsigned bd, std::size_t h, std::size_t w, unsigned rt) :
        Graphical_File(fn, bd, h, w), RUNTIME_FRAMES(rt) { MB = gif_size(); };

    double gif_size();
    void print(std::ostream&) const override;
private:
    unsigned RUNTIME_FRAMES = 0;
    const std::string TYPE = "GIF";
};

///////////////////////////////////////////////////

void Graphical_File::print(std::ostream &os) const {
    os << "File: " << FILE_NAME
       << "\nSize: " << std::setprecision(4) << MB << "MB"
       << "\nResolution: " << W_PIXELS << "x" << H_PIXELS << std::endl; 
}

void JPEG::print(std::ostream &os) const {
    Graphical_File::print(os);
    os << "Compression: " << COMPRESSION << "%"
       << "\nFile Type: " << TYPE << std::endl;
}

void TIFF::print(std::ostream &os) const {
    Graphical_File::print(os);
    os << "Compression Tag: " << COMPRESSION_TAG
       << "\nFile Type: " << TYPE << std::endl;
}

void GIF::print(std::ostream &os) const {
    Graphical_File::print(os);
    os << "Runtime: " << RUNTIME_FRAMES << " Frames"
       << "\nFile Type: " << TYPE << std::endl;
}

///////////////////////////////////////////////

void Graphical_File::crop(std::size_t h, std::size_t w) {
    H_PIXELS = h;
    W_PIXELS = w;
    MB = calculate_mb();
}

double Graphical_File::calculate_mb() {
    return (((((H_PIXELS*W_PIXELS) * BITDEPTH) / 8) / 1024) / 1024);
}

double GIF::gif_size() {
    return MB * RUNTIME_FRAMES;
}

#endif