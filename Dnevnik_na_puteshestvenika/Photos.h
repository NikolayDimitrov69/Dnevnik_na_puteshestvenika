#ifndef IOSTR_PHOTOS_H
#define IOSTR_PHOTOS_H

#include <string>
#include <iterator>
#include <iostream>

class Photos
{
private:
    std::string photos;
public:
    Photos() = default;

    Photos(const std::string& _photos)
    {
        photos = _photos;
    }

    const std::string& getPhotos() const
    {
        return photos;
    }

    bool validate()
    {
        // TODO: check Photos and return false if invalid
        return true;
    }


};

std::ostream& operator<<(std::ostream& os, const Photos& v);

std::istream& operator>>(std::istream& is, Photos& v);

#endif //IOSTR_PHOTOS_H