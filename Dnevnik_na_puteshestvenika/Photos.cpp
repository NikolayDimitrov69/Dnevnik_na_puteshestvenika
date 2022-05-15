#include "Photos.h"

//! Функция за замяна на буква с друга буква
std::string replace_all(const std::string& in, char what, char with)
{
    std::string result = in;
    for (unsigned i = 0; i < result.size(); ++i)
    {
        if (result[i] == what) result[i] = with;
    }
    return result;
}

//! Функция за премахване на повтарящи се разстояния както и тези в началото и края
std::string remove_extra_spaces(const std::string& in)
{
    std::string result;
    bool add_space = false;
    for (auto c : in)
    {
        if (c == ' ')
        {
            if (!result.empty() && result.back() != ' ') add_space = true;
        }
        else
        {
            if (add_space)
            {
                result.push_back(' ');
                add_space = false;
            }
            result.push_back(c);
        }
    }
    return result;
}

std::istream& operator>>(std::istream& is, Photos& photos)
{
    //! Локална променлива
    std::string _photos;

    if (is.rdbuf() == std::cin.rdbuf())
    {
        std::cout << "Enter photos: ";
        //! https://en.cppreference.com/w/cpp/io/manip/ws
        std::getline(is >> std::ws, _photos);
        _photos = remove_extra_spaces(_photos);
        _photos = replace_all(_photos, ' ', ',');
    }
    else
    {
        is >> _photos;
    }

    photos = Photos(_photos);

    return is;
}

std::ostream& operator<<(std::ostream& os, const Photos& photos)
{
    if (os.rdbuf() == std::cout.rdbuf())
    {
        os << "Photos: " << photos.getPhotos();
    }
    else
    {
        os << photos.getPhotos();
    }
    return os;
}

