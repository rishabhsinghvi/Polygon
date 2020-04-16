#ifndef POLYGON_INPUT_KEYCODES_H
#define POLYGON_INPUT_KEYCODES_H

namespace PolygonEngine
{
	namespace Input
	{
		enum MouseInput
		{
			MOUSE_LEFT,
			MOUSE_RIGHT,
			MOUSE_MIDDLE,
			MOUSE_MOUSE4,
			MOUSE_MOUSE5
		};

		enum KeyboardInput
		{
			/// Letter keys
			KEY_A,
			KEY_B,
			KEY_C,
			KEY_D,
			KEY_E,
			KEY_F,
			KEY_G,
			KEY_H,
			KEY_I,
			KEY_J,
			KEY_K,
			KEY_L,
			KEY_M,
			KEY_N,
			KEY_O,
			KEY_P,
			KEY_Q,
			KEY_R,
			KEY_S,
			KEY_T,
			KEY_U,
			KEY_V,
			KEY_W,
			KEY_X,
			KEY_Y,
			KEY_Z,

			/// Number keys
			KEY_0,
			KEY_1,
			KEY_2,
			KEY_3,
			KEY_4,
			KEY_5,
			KEY_6,
			KEY_7,
			KEY_8,
			KEY_9,

			/// Miscellaneous
			KEY_LSHIFT,
			KEY_RSHIFT,
			KEY_LCTRL,
			KEY_RCTRL,
			KEY_LALT,
			KEY_RALT,
			KEY_BACKSPACE,
			KEY_TILDE,
			KEY_COMMA,
			KEY_PLUS,
			KEY_MINUS,
			KEY_PERIOD,
			KEY_SLASH,


			/// Arrow keys
			KEY_UPARROW,
			KEY_DOWNARROW,
			KEY_LEFTARROW,
			KEY_RIGHTARROW,


			// Numpad keys
			KEY_NUM_1,
			KEY_NUM_2,
			KEY_NUM_3,
			KEY_NUM_4,
			KEY_NUM_5,
			KEY_NUM_6,
			KEY_NUM_7,
			KEY_NUM_8,
			KEY_NUM_9,
			KEY_NUM_STAR,
			KEY_NUM_SLASH,
			KEY_NUM_PERIOD,
			KEY_NUM_MINUS,
			KEY_NUM_PLUS,
			KEY_NUM_RETURN,

			/// Function keys
			KEY_F1,
			KEY_F2,
			KEY_F3,
			KEY_F4,
			KEY_F5,
			KEY_F6,
			KEY_F7,
			KEY_F8,
			KEY_F9,
			KEY_F10,
			KEY_F11,
			KEY_F12,

		};
	}
}

#endif