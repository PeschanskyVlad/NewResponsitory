//
     // SFML - Simple and Fast Multimedia Library
     // Copyright (C) 2007-2013 Laurent Gomila (laurent.gom@gmail.com)
     //
     // This software is provided 'as-is', without any express or implied warranty.
     // In no event will the authors be held liable for any damages arising from the use of this software.
     //
     // Permission is granted to anyone to use this software for any purpose,
    // including commercial applications, and to alter it and redistribute it freely,
    // subject to the following restrictions:
    //
    // 1. The origin of this software must not be misrepresented;
    //    you must not claim that you wrote the original software.
    //    If you use this software in a product, an acknowledgment
    //    in the product documentation would be appreciated but is not required.
    //
    // 2. Altered source versions must be plainly marked as such,
    //    and must not be misrepresented as being the original software.
    //
    // 3. This notice may not be removed or altered from any source distribution.
    //

    #ifndef SFML_COLOR_HPP
    #define SFML_COLOR_HPP

    // Headers
    #include <SFML/Graphics/Export.hpp>

   33
   34 namespace sf
   35 {
   40 class SFML_GRAPHICS_API Color
   41 {
   42 public :
   43
   51     Color();
   52
   62     Color(Uint8 red, Uint8 green, Uint8 blue, Uint8 alpha = 255);
   63
   65     // Static member data
   67     static const Color Black;
   68     static const Color White;
   69     static const Color Red;
   70     static const Color Green;
   71     static const Color Blue;
   72     static const Color Yellow;
   73     static const Color Magenta;
   74     static const Color Cyan;
   75     static const Color Transparent;
   76
   78     // Member data
   80     Uint8 r;
   81     Uint8 g;
   82     Uint8 b;
   83     Uint8 a;
   84 };
   85
   98 SFML_GRAPHICS_API bool operator ==(const Color& left, const Color& right);
   99
  112 SFML_GRAPHICS_API bool operator !=(const Color& left, const Color& right);
  113
  127 SFML_GRAPHICS_API Color operator +(const Color& left, const Color& right);
  128
  144 SFML_GRAPHICS_API Color operator *(const Color& left, const Color& right);
  145
  160 SFML_GRAPHICS_API Color& operator +=(Color& left, const Color& right);
  161
  178 SFML_GRAPHICS_API Color& operator *=(Color& left, const Color& right);
  179
  180 } // namespace sf
  181
  182
  183 #endif // SFML_COLOR_HPP
