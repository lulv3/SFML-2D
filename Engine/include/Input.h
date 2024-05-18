#ifndef INPUT_H
#define INPUT_H

#include <SFML/Graphics.hpp>

class Input
{
public:

    enum Key {
        A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z,
        Num0, Num1, Num2, Num3, Num4, Num5, Num6, Num7, Num8, Num9,
        Escape, LControl, LShift, LAlt, LSystem, RControl, RShift, RAlt, RSystem,
        Menu, LBracket, RBracket, Semicolon, Comma, Period, Quote, Slash, Backslash,
        Tilde, Equal, Hyphen, Space, Enter, Backspace, Tab, PageUp, PageDown, End, Home,
        Insert, Delete, Add, Subtract, Multiply, Divide, Left, Right, Up, Down,
        Numpad0, Numpad1, Numpad2, Numpad3, Numpad4, Numpad5, Numpad6, Numpad7, Numpad8, Numpad9,
        F1, F2, F3, F4, F5, F6, F7, F8, F9, F10, F11, F12, F13, F14, F15,
        Pause
    };


	static bool isKeyPressed(Key key)
	{
        switch (key) {
        case A: return sf::Keyboard::isKeyPressed(sf::Keyboard::A);
        case B: return sf::Keyboard::isKeyPressed(sf::Keyboard::B);
        case C: return sf::Keyboard::isKeyPressed(sf::Keyboard::C);
        case D: return sf::Keyboard::isKeyPressed(sf::Keyboard::D);
        case E: return sf::Keyboard::isKeyPressed(sf::Keyboard::E);
        case F: return sf::Keyboard::isKeyPressed(sf::Keyboard::F);
        case G: return sf::Keyboard::isKeyPressed(sf::Keyboard::G);
        case H: return sf::Keyboard::isKeyPressed(sf::Keyboard::H);
        case I: return sf::Keyboard::isKeyPressed(sf::Keyboard::I);
        case J: return sf::Keyboard::isKeyPressed(sf::Keyboard::J);
        case K: return sf::Keyboard::isKeyPressed(sf::Keyboard::K);
        case L: return sf::Keyboard::isKeyPressed(sf::Keyboard::L);
        case M: return sf::Keyboard::isKeyPressed(sf::Keyboard::M);
        case N: return sf::Keyboard::isKeyPressed(sf::Keyboard::N);
        case O: return sf::Keyboard::isKeyPressed(sf::Keyboard::O);
        case P: return sf::Keyboard::isKeyPressed(sf::Keyboard::P);
        case Q: return sf::Keyboard::isKeyPressed(sf::Keyboard::Q);
        case R: return sf::Keyboard::isKeyPressed(sf::Keyboard::R);
        case S: return sf::Keyboard::isKeyPressed(sf::Keyboard::S);
        case T: return sf::Keyboard::isKeyPressed(sf::Keyboard::T);
        case U: return sf::Keyboard::isKeyPressed(sf::Keyboard::U);
        case V: return sf::Keyboard::isKeyPressed(sf::Keyboard::V);
        case W: return sf::Keyboard::isKeyPressed(sf::Keyboard::W);
        case X: return sf::Keyboard::isKeyPressed(sf::Keyboard::X);
        case Y: return sf::Keyboard::isKeyPressed(sf::Keyboard::Y);
        case Z: return sf::Keyboard::isKeyPressed(sf::Keyboard::Z);
        case Num0: return sf::Keyboard::isKeyPressed(sf::Keyboard::Num0);
        case Num1: return sf::Keyboard::isKeyPressed(sf::Keyboard::Num1);
        case Num2: return sf::Keyboard::isKeyPressed(sf::Keyboard::Num2);
        case Num3: return sf::Keyboard::isKeyPressed(sf::Keyboard::Num3);
        case Num4: return sf::Keyboard::isKeyPressed(sf::Keyboard::Num4);
        case Num5: return sf::Keyboard::isKeyPressed(sf::Keyboard::Num5);
        case Num6: return sf::Keyboard::isKeyPressed(sf::Keyboard::Num6);
        case Num7: return sf::Keyboard::isKeyPressed(sf::Keyboard::Num7);
        case Num8: return sf::Keyboard::isKeyPressed(sf::Keyboard::Num8);
        case Num9: return sf::Keyboard::isKeyPressed(sf::Keyboard::Num9);
        case Escape: return sf::Keyboard::isKeyPressed(sf::Keyboard::Escape);
        case LControl: return sf::Keyboard::isKeyPressed(sf::Keyboard::LControl);
        case LShift: return sf::Keyboard::isKeyPressed(sf::Keyboard::LShift);
        case LAlt: return sf::Keyboard::isKeyPressed(sf::Keyboard::LAlt);
        case LSystem: return sf::Keyboard::isKeyPressed(sf::Keyboard::LSystem);
        case RControl: return sf::Keyboard::isKeyPressed(sf::Keyboard::RControl);
        case RShift: return sf::Keyboard::isKeyPressed(sf::Keyboard::RShift);
        case RAlt: return sf::Keyboard::isKeyPressed(sf::Keyboard::RAlt);
        case RSystem: return sf::Keyboard::isKeyPressed(sf::Keyboard::RSystem);
        case Menu: return sf::Keyboard::isKeyPressed(sf::Keyboard::Menu);
        case LBracket: return sf::Keyboard::isKeyPressed(sf::Keyboard::LBracket);
        case RBracket: return sf::Keyboard::isKeyPressed(sf::Keyboard::RBracket);
        case Semicolon: return sf::Keyboard::isKeyPressed(sf::Keyboard::Semicolon);
        case Comma: return sf::Keyboard::isKeyPressed(sf::Keyboard::Comma);
        case Period: return sf::Keyboard::isKeyPressed(sf::Keyboard::Period);
        case Quote: return sf::Keyboard::isKeyPressed(sf::Keyboard::Quote);
        case Slash: return sf::Keyboard::isKeyPressed(sf::Keyboard::Slash);
        case Backslash: return sf::Keyboard::isKeyPressed(sf::Keyboard::Backslash);
        case Tilde: return sf::Keyboard::isKeyPressed(sf::Keyboard::Tilde);
        case Equal: return sf::Keyboard::isKeyPressed(sf::Keyboard::Equal);
        case Hyphen: return sf::Keyboard::isKeyPressed(sf::Keyboard::Hyphen);
        case Space: return sf::Keyboard::isKeyPressed(sf::Keyboard::Space);
        case Enter: return sf::Keyboard::isKeyPressed(sf::Keyboard::Enter);
        case Backspace: return sf::Keyboard::isKeyPressed(sf::Keyboard::Backspace);
        case Tab: return sf::Keyboard::isKeyPressed(sf::Keyboard::Tab);
        case PageUp: return sf::Keyboard::isKeyPressed(sf::Keyboard::PageUp);
        case PageDown: return sf::Keyboard::isKeyPressed(sf::Keyboard::PageDown);
        case End: return sf::Keyboard::isKeyPressed(sf::Keyboard::End);
        case Home: return sf::Keyboard::isKeyPressed(sf::Keyboard::Home);
        case Insert: return sf::Keyboard::isKeyPressed(sf::Keyboard::Insert);
        case Delete: return sf::Keyboard::isKeyPressed(sf::Keyboard::Delete);
        case Add: return sf::Keyboard::isKeyPressed(sf::Keyboard::Add);
        case Subtract: return sf::Keyboard::isKeyPressed(sf::Keyboard::Subtract);
        case Multiply: return sf::Keyboard::isKeyPressed(sf::Keyboard::Multiply);
        case Divide: return sf::Keyboard::isKeyPressed(sf::Keyboard::Divide);
        case Left: return sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
        case Right: return sf::Keyboard::isKeyPressed(sf::Keyboard::Right);
        case Up: return sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
        case Down: return sf::Keyboard::isKeyPressed(sf::Keyboard::Down);
        case Numpad0: return sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad0);
        case Numpad1: return sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad1);
        case Numpad2: return sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad2);
        case Numpad3: return sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad3);
        case Numpad4: return sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad4);
        case Numpad5: return sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad5);
        case Numpad6: return sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad6);
        case Numpad7: return sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad7);
        case Numpad8: return sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad8);
        case Numpad9: return sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad9);
        case F1: return sf::Keyboard::isKeyPressed(sf::Keyboard::F1);
        case F2: return sf::Keyboard::isKeyPressed(sf::Keyboard::F2);
        case F3: return sf::Keyboard::isKeyPressed(sf::Keyboard::F3);
        case F4: return sf::Keyboard::isKeyPressed(sf::Keyboard::F4);
        case F5: return sf::Keyboard::isKeyPressed(sf::Keyboard::F5);
        case F6: return sf::Keyboard::isKeyPressed(sf::Keyboard::F6);
        case F7: return sf::Keyboard::isKeyPressed(sf::Keyboard::F7);
        case F8: return sf::Keyboard::isKeyPressed(sf::Keyboard::F8);
        case F9: return sf::Keyboard::isKeyPressed(sf::Keyboard::F9);
        case F10: return sf::Keyboard::isKeyPressed(sf::Keyboard::F10);
        case F11: return sf::Keyboard::isKeyPressed(sf::Keyboard::F11);
        case F12: return sf::Keyboard::isKeyPressed(sf::Keyboard::F12);
        case Pause: return sf::Keyboard::isKeyPressed(sf::Keyboard::Pause);
        }
	}

private:

    bool isKeyPressedCheck(Key key) {
        
    }
};

#endif // !INPUT_H
