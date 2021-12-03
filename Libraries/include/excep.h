#include <exception>
#include <iostream>
class OpeningVideoError : public std::exception{
    public:
        OpeningVideoError() noexcept;
        virtual ~OpeningVideoError() noexcept;
        virtual const char * what() const noexcept;
};