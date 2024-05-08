#pragma once
using namespace System;
using namespace System::Windows::Forms;
using namespace System::Collections::Generic;
using namespace System::Drawing;

namespace Creatures {
	public ref class RotationalObject : PictureBox {

		public: int size = 100;

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
		public:

			float Speed = 5;

			List<Point>^ Movement_path;
			int progress = 0;

			int mid_point = 3;

			bool isFinished() {
				return progress == Movement_path->Count;
			}

			bool isMidPoint() {
				return progress == mid_point;
			}

			void move() {
				
				Point Center = this->Location;

				Center.Offset(Point(size / 2, size / 2));

				if (isFinished()) return;
				if (Center == Movement_path[progress]) { progress++; return; }

				

				Point delta = Point(0, 0);

				delta.Offset(Center);
				delta.X *= -1;
				delta.Y *= -1;

				delta.Offset(Movement_path[progress]);

				if (delta.X > Speed) { delta.X = Speed; Rotate(Direction::Right); }
				if (delta.X < -Speed) { delta.X = -Speed; Rotate(Direction::Left); }
				if (delta.Y > Speed) { delta.Y = Speed; Rotate(Direction::Down); }
				if (delta.Y < -Speed) { delta.Y = -Speed; Rotate(Direction::Up); }



				Fly(delta.X, delta.Y);



			}

	};

	public delegate void FlewAwayHandler();
	public delegate void LandedHandler();

	public ref class Plane : PlanedMovementObject {
		
		protected:
			float XVelocity = 0;
			float YVelocity = 0;

			const float XAcceleration = 0.1;
			const float YAcceleration = -0.1;

			const float ReqXVelocity = 7;
			const float TopXVelocity = 15;
			const float TopYVelocity = 5;
			bool grounded = true;


		protected: 
			static String^ ImagePath = "plane_grounded.bmp";

		public:
			List<Point>^ LandingMovement_path;
			event FlewAwayHandler^ FlewAway;
			event LandedHandler^ Landed;
			String^ state = "Idle3";
			bool loaded = true;
			bool airport_is_busy = true;

			Plane::Plane() {

			}

			Plane::Plane(Form^ World, Point location, int size_) {
				state = "Idle3";
				size = size_;
				ChangeImage(ImagePath, size);
				location.Offset(Point(-size / 2, -size / 2));
				InitInsect(World, location);
			}

			void UnGround() {
				if (grounded == false) return;
				grounded = false;
				//ChangeImage(ImagePathUnGrounded, size);
				Rotate(Direction::Right);
			}

			void prepare_to_fly() {
				Speed = 5;
				YVelocity = 0;
				XVelocity = Speed;
				state = "moving_to_VPP";
				Movement_path->Reverse();
				progress = 0;
			}

			void prepare_to_land(List<Point>^ Movement_path_) {
				Speed = 5;
				XVelocity = -2.5 * Speed;
				YVelocity = 2;

				state = "landing";
				Movement_path_->Reverse();
				Movement_path = Movement_path_;
				progress = 0;
			}

			void prepare_to_wait(List<Point>^ Movement_path_) {
				Speed = 12;

				state = "wait";
				Movement_path = Movement_path_;
				progress = 0;
			}

			public: enum class Callback
			{
				Default,
				Bus
			};

			int idler = 0;
			Callback tick() {
				if (state == "flewaway") { Console::WriteLine("H1"); return Callback::Default;  }

				if (state == "Idle") { Console::WriteLine("Idle");  return Callback::Default; }

				if (state == "wait" && isFinished()) { if (airport_is_busy) { progress = 0; } else { prepare_to_land(LandingMovement_path); }  Console::WriteLine("wait");  return Callback::Default; }
				if (state == "wait") { move();  Console::WriteLine("wait");  return Callback::Default; }

				if (state == "landing") { land(); Console::WriteLine("H2"); return Callback::Default; }


				if (state == "moving_to_hung" && isFinished()) { state = "Idle"; Console::WriteLine("H3"); Landed(); return Callback::Default; }
				if (state == "moving_to_hung" && (!isMidPoint() || !loaded)) { move(); Console::WriteLine("H4"); return Callback::Default; }
				if (state == "moving_to_hung") { Console::WriteLine("cargo"); return Callback::Bus; }

				if ((state == "moving_to_VPP" || state == "flying") && isFinished()) { state = "flying"; Fly_VPP(); Rotate(Direction::Right); Console::WriteLine("H5"); return Callback::Default; };
				if (state == "moving_to_VPP" && (!isMidPoint() || loaded)) { move(); Console::WriteLine("H6"); return Callback::Default; }
				if (state == "moving_to_VPP") { Console::WriteLine("cargo"); return Callback::Bus; }
				
			}

			void Fly_VPP() {
				XVelocity += XAcceleration;
				if (XVelocity > ReqXVelocity) {
					YVelocity += YAcceleration;
					UnGround();
				}
				if (this->Location.X > 1500) {
					state = "flewaway";
					FlewAway();
				}
				Fly(XVelocity, YVelocity);
				//Rotate(Direction::Down);
			}

			void land() {
				
				int still_accelerating = 0;

				if (this->Location.Y >= 189 - size / 2) {
					this->Location = Point(this->Location.X, 189 - size / 2);
					YVelocity = 0;
					++still_accelerating;
					XVelocity += XAcceleration;
				}

				
				
				if (XVelocity > -1 * Speed) {
					XVelocity = -Speed;
					++still_accelerating;
				}

				if (still_accelerating == 2) {
					state = "moving_to_hung";
				}
				
				Fly(XVelocity, YVelocity);
			}
	};


	public ref class Bus : PlanedMovementObject {
		
		static String^ ImagePath = "bus.bmp";

	public:
		Bus::Bus(Form^ World, Point location, int size_) {
			size = size_;
			ChangeImage(ImagePath, size);
			location.Offset(Point(-size / 2, -size / 2));
			InitInsect(World, location);
		}

		enum class Callback
		{
			Default,
			FinishedLoading,
			Delivered
		};

		int ticks_waiting = 0;
		Callback tick() {
			move();
			if (isFinished()) ticks_waiting++;
			if (ticks_waiting == 100) {
				progress = 0;
				Movement_path->Reverse();
				ticks_waiting++;
			}

			if (ticks_waiting >= 100) {
				if (isFinished()) { progress = 0; ticks_waiting = 0; Movement_path->Reverse(); Console::WriteLine("delivered"); return Callback::Delivered; }
				return Callback::FinishedLoading;
			}
			return Callback::Default;
		}
	};
}
