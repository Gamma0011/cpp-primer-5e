#ifndef GRAPHICAL_FILE_FORMATS_H
#define GRAPHICAL_FILE_FORMATS_H

#include <iostream>
#include <string>

class Graphical_File {
public:
    std::string FILE_NAME;

    Graphical_File() = default;
    Graphical_File(std::string fn, std::size_t sz, std::size_t h, std::size_t w) :
        FILE_NAME(fn), MB(sz), H_PIXELS(h), W_PIXELS(w) { };
    virtual ~Graphical_File() = default;

    virtual void print(std::ostream&) const;
private:
    std::size_t MB = 0;
    std::size_t H_PIXELS = 0;
    std::size_t W_PIXELS = 0;
};

class JPEG : public Graphical_File {
public:
    JPEG() = default;
    JPEG(std::string fn, std::size_t sz, std::size_t h, std::size_t w, double c) :
        Graphical_File(fn, sz, h, w), COMPRESSION(c) { };

    void print(std::ostream&) const override;
private: 
    double COMPRESSION = 0;
    const std::string TYPE = "JPEG";
};

class TIFF : public Graphical_File {
public:
    TIFF() = default;
    TIFF(std::string fn, std::size_t sz, std::size_t h, std::size_t w, std::string c) :
        Graphical_File(fn, sz, h, w), COMPRESSION_TAG(c) { };
    
    void print(std::ostream&) const override;
private: 
    std::string COMPRESSION_TAG = "";
    const std::string TYPE = "TIFF";
};

class GIF : public Graphical_File {
public:
    GIF() = default;
    GIF(std::string fn, std::size_t sz, std::size_t h, std::size_t w, double rt) :
        Graphical_File(fn, sz, h, w), RUNTIME(rt) { };

    void print(std::ostream&) const override;
private:
    double RUNTIME = 0.0;
    const std::string TYPE = "GIF";
};

///////////////////////////////////////////////////

void Graphical_File::print(std::ostream &os) const {
    os << "File: " << FILE_NAME
       << "\nSize: " << MB << "MBs"
       << "\nResolution: " << W_PIXELS << "x" << H_PIXELS << std::endl; 
}

void JPEG::print(std::ostream &os) const {
    Graphical_File::print(os);
    os << "Compression: " << COMPRESSION
       << "\nFile Type: " << TYPE << std::endl;
}

void TIFF::print(std::ostream &os) const {
    Graphical_File::print(os);
    os << "Compression Tag: " << COMPRESSION_TAG
       << "\nFile Type: " << TYPE << std::endl;
}

void GIF::print(std::ostream &os) const {
    Graphical_File::print(os);
    os << "Runtime: " << RUNTIME
       << "\nFile Type: " << TYPE << std::endl;
}

#endif