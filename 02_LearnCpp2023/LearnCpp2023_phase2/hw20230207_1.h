#pragma once

namespace hw20230207_1 {
	class Report {
	private:
		int m_iMath;
		int m_iKra;
		int m_iEng;
		float m_fAvg;
		char m_szName[20];
		char m_cScore;

		// func
		void CalcAvg();
		void CalcScore();
	
	public:
		Report();

		void InitReport(int _iKra, int _iMath, int _iEng, char _szName[]);

		//get
		int GetiMath();
		int GetiKra();
		int GetiEng();
		const char* GetszName();
		char GetcScore();

		//set
		void SetiMath(int _iMath);
		void SetiKra(int _iKra);
		void SetiEng(int _iEng);
		void SetszName(char _szName[]);


		//func
		void ShowReport();
		void CopyReport(const Report& _report);

	};
}