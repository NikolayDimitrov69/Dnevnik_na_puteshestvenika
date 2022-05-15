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
   
    const std::string& getPhotos() const
    {
        return photos;
    }

    Photos() = default;

    Photos(const std::string& _photos)
    {
        photos = _photos;
    }
};

std::istream& operator>>(std::istream&, Photos&);

std::ostream& operator<<(std::ostream&, const Photos&);



#endif //IOSTR_PHOTOS_H