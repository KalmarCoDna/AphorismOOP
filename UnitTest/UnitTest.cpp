#include "pch.h"
#include "CppUnitTest.h"

#include "../АфоризмыООП/Header.h"
#include "../АфоризмыООП/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:

		TEST_METHOD(In_Aphorism_Test)
		{
			Aphorism* A_exp = new Aphorism;

			A_exp->Set_Author("Benjamin Disraeli");

			Storehouse* St_act = new Aphorism;

			ifstream ifst("../АфоризмыООП/in_aphorism.txt");

			St_act->In_Data(ifst);

			Assert::AreEqual(A_exp->Get_Author(), ((Aphorism*)St_act)->Get_Author());
		}
		TEST_METHOD(In_Proverb_Test)
		{
			Proverb* P_exp = new Proverb;

			P_exp->Set_Country("England");

			Storehouse* St_act = new Proverb;

			ifstream ifst("../АфоризмыООП/in_proverb.txt");

			St_act->In_Data(ifst);

			Assert::AreEqual(P_exp->Get_Country(), ((Proverb*)St_act)->Get_Country());
		}
		TEST_METHOD(In_Riddle_Test)
		{
			Riddle* R_exp = new Riddle;

			R_exp->Set_Answer("Clock");

			Storehouse* St_act = new Riddle;

			ifstream ifst("../АфоризмыООП/in_riddle.txt");

			St_act->In_Data(ifst);

			Assert::AreEqual(R_exp->Get_Answer(), ((Riddle*)St_act)->Get_Answer());
		}
		TEST_METHOD(In_Storehouse_Test)
		{
			Riddle* R_exp = new Riddle;

			R_exp->Set_Content("What has a face and two hands but no arms or legs?");
			R_exp->Set_Answer("Clock");
			R_exp->Set_Estimation(3);

			Storehouse* St_exp = R_exp;

			//Storehouse* St_act = new Riddle;

			ifstream ifst("../АфоризмыООП/in_storehouse.txt");

			Storehouse* St_act = Storehouse::In(ifst);

			Assert::AreEqual(St_exp->Get_Content(), St_act->Get_Content());
			Assert::AreEqual(((Riddle*)St_exp)->Get_Answer(), ((Riddle*)St_act)->Get_Answer());
			Assert::AreEqual(St_exp->Get_Estimation(), St_act->Get_Estimation());
		}
		TEST_METHOD(Out_Aphorism_Text)
		{
			Aphorism* A_act = new Aphorism;

			A_act->Set_Author("Benjamin Disraeli");

			ofstream ofst("../АфоризмыООП/out_aphorism_act.txt");

			Storehouse* St_act = A_act;

			St_act->Set_Content("Success is the child of audacity.");
			St_act->Set_Estimation(7);

			St_act->Out_Data(St_act->Get_Content(), St_act->Get_Estimation(), ofst);

			ifstream ifst_exp("../АфоризмыООП/out_aphorism_exp.txt");
			ifstream ifst_act("../АфоризмыООП/out_aphorism_act.txt");

			string Exp;
			getline(ifst_exp, Exp, '\0');
			string Act;
			getline(ifst_act, Act, '\0');

			Assert::AreEqual(Exp, Act);
		}
		TEST_METHOD(Out_Proverb_Text)
		{
			Proverb* P_act = new Proverb;

			P_act->Set_Country("England");

			ofstream ofst("../АфоризмыООП/out_proverb_act.txt");

			Storehouse* St_act = P_act;

			St_act->Set_Content("Two wrongs don't make a right.");
			St_act->Set_Estimation(4);

			St_act->Out_Data(St_act->Get_Content(), St_act->Get_Estimation(), ofst);

			ifstream ifst_exp("../АфоризмыООП/out_proverb_exp.txt");
			ifstream ifst_act("../АфоризмыООП/out_proverb_act.txt");

			string Exp;
			getline(ifst_exp, Exp, '\0');
			string Act;
			getline(ifst_act, Act, '\0');

			Assert::AreEqual(Exp, Act);
		}
		TEST_METHOD(Out_Riddle_Text)
		{
			Riddle* R_act = new Riddle;

			R_act->Set_Answer("Clock");

			ofstream ofst("../АфоризмыООП/out_riddle_act.txt");

			Storehouse* St_act = R_act;

			St_act->Set_Content("What has a face and two hands but no arms or legs?");
			St_act->Set_Estimation(3);

			St_act->Out_Data(St_act->Get_Content(), St_act->Get_Estimation(), ofst);

			ifstream ifst_exp("../АфоризмыООП/out_riddle_exp.txt");
			ifstream ifst_act("../АфоризмыООП/out_riddle_act.txt");

			string Exp;
			getline(ifst_exp, Exp, '\0');
			string Act;
			getline(ifst_act, Act, '\0');

			Assert::AreEqual(Exp, Act);
		}
		TEST_METHOD(Amount_Test)
		{
			Riddle* R = new Riddle;

			R->Set_Content("What has a face and two hands but no arms or legs?");

			Storehouse* St = R;

			int Amount_exp = 1;
			int Amount_act = St->Amount();
			Assert::AreEqual(Amount_exp, Amount_act);
		}
		TEST_METHOD(Compare_Test)
		{
			Riddle* R = new Riddle;

			R->Set_Content("What has a face and two hands but no arms or legs?");

			Storehouse* St_First = R;

			Aphorism* A = new Aphorism;

			A->Set_Content("Success is the child of audacity.");

			Storehouse* St_Second = A;

			bool Act = St_First->Compare(St_Second);
			bool Exp = false;

			Assert::AreEqual(Exp, Act);
		}
		TEST_METHOD(Sort_Test)
		{
			ifstream ifst("../АфоризмыООП/input.txt");
			Container c;

			c.In(ifst);

			ofstream ofst("../АфоризмыООП/sort_act.txt");

			c.Sort();

			c.Out(ofst);

			ifstream ifst_exp("../АфоризмыООП/sort_exp.txt");
			ifstream ifst_act("../АфоризмыООП/sort_act.txt");

			string Exp;
			getline(ifst_exp, Exp, '\0');
			string Act;
			getline(ifst_act, Act, '\0');

			Assert::AreEqual(Exp, Act);
		}
	};
}
