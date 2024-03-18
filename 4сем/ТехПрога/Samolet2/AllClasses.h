#pragma once
using namespace System;
using namespace System::Windows::Forms;
using namespace System::Collections::Generic;
using namespace System::Drawing;

namespace Creatures {
	public ref class RotationalObject : PictureBox {

		protected: static String^ ImagePath = "test.bmp";
		protected: static int FlightStep = 30;

		public: enum class Direction
		{
			None,
			Up,
			Right,
			Down,
			Left
		};

		private: Direction CurrentDirection = Direction::Up;

			   //private: static String^ ImagePath = "\\..\\pictures\\Insect.png"; // still sucks

		public: RotationalObject::RotationalObject() {

		}

		public: void ChangeImage(String^ ImagePath, int size) {
			this->CurrentDirection = Direction::Up;
			this->Size = System::Drawing::Size(size, size);
			auto img = gcnew Bitmap(ImagePath);
			this->Image = img;
		}

		public: RotationalObject::RotationalObject(Form^ World, Point location) {
			this->Size = System::Drawing::Size(FlightStep, FlightStep);
			auto img = gcnew Bitmap(ImagePath);
			this->Image = img;
			InitInsect(World, location);
		}
		protected: void InitInsect(Form^ World, Point location) {
			World->Controls->Add(this);
			this->Location = location;
			this->SizeMode = PictureBoxSizeMode::StretchImage;
		}
		public: void Birth(Form^ World) {
			World->Controls->Add(this);
			this->Location = System::Drawing::Point(200, 200);
		}
		public: void Birth(Form^ World, Point BirthLocation) {
			World->Controls->Add(this);
			this->Location = BirthLocation;//System::Drawing::Point(200, 200);
		}

		public: void Fly(int OffsetX, int OffsetY) {
			this->Location = Point(this->Location.X + OffsetX, this->Location.Y + OffsetY);
		}
		public: void Fly(Direction direction) {
			Rotate(direction);

			switch (direction)
			{
			case Direction::Up:
				//this->Location = Point(this->Location.X, this->Location.Y + FlightStep);
				this->Location = Point(this->Location.X, this->Location.Y - FlightStep);
				break;
			case Direction::Right:
				this->Location = Point(this->Location.X + FlightStep, this->Location.Y);
				break;
			case Direction::Down:
				//this->Location = Point(this->Location.X, this->Location.Y - FlightStep);
				this->Location = Point(this->Location.X, this->Location.Y + FlightStep);
				break;
			case Direction::Left:
				this->Location = Point(this->Location.X - FlightStep, this->Location.Y);
				break;
			default:
				return;
			}
		}

		public : void Rotate(Direction direction) {
			
			int WhereToRotate = Convert::ToInt32(direction) - Convert::ToInt32(CurrentDirection);
			if (WhereToRotate < 0) {
				WhereToRotate += 4;
			}

			
			auto img = this->Image;
			img->RotateFlip(RotateFlipType(WhereToRotate));

			this->Image = img;
			this->CurrentDirection = direction;
			//this->Image->RotateFlip(RotateFlipType(WhereToRotate));

			//this->Image->RotateFlip(RotateFlipType::Rotate90FlipNone);
			//this->Image->RotateFlip(RotateFlipType::Rotate180FlipNone);
			//this->Image->RotateFlip(RotateFlipType::Rotate270FlipNone);
		}
		
	};


	public ref class PlanedMovementObject : RotationalObject{
		//List<Point>^
	};

	public ref class Plane : RotationalObject {
		
		protected:
			float XVelocity = 0;
			float YVelocity = 0;

			const float XAcceleration = 0.1;
			const float YAcceleration = -0.1;

			const float ReqXVelocity = 7;
			const float TopXVelocity = 15;
			const float TopYVelocity = 5;
			bool grounded = true;
			Direction DirectionHeading = Direction::Right;
	
		protected: 
			static String^ ImagePathGrounded = "plane_grounded.bmp";
			static String^ ImagePathUnGrounded = "plane_ungrounded.bmp";

		public:
			Plane::Plane(Form^ World, Point location, int size) {
				ChangeImage(ImagePathGrounded, 100);
				InitInsect(World, location);
			}

			void UnGround() {
				if (grounded == false) return;
				grounded = false;
				ChangeImage(ImagePathUnGrounded, 100);
				Rotate(Direction::Right);
			}

			void tick() {
				XVelocity += XAcceleration;
				if (XVelocity > ReqXVelocity) {
					YVelocity += YAcceleration;
					UnGround();
				}
				Fly(XVelocity, YVelocity);
				//Rotate(Direction::Down);
			}
	};
}
