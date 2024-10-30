#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>
#include <ftxui/screen/color.hpp>
#include <ftxui/screen/terminal.hpp>
#include <iostream>
#include <thread>

using namespace std;
using namespace ftxui;

int main(int argc, char const *argv[])
{
    std::string reset_position;
    int frame = 0;

    while (true)
    {
        Screen pantalla = Screen::Create(Dimension::Full(), Dimension::Full());

        auto can = Canvas(100,100);
        can.DrawPointCircle(50, 50, frame);

        Element lienzo = bgcolor(Color::Aquamarine1, canvas(&can));
        Render(pantalla, lienzo);
        
        
        std::cout << reset_position;
        pantalla.Print();
        reset_position = pantalla.ResetPosition(true);
        
        this_thread::sleep_for(0.1s);
        frame++;
    }

    return 0;
}