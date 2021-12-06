#include <iostream>
#include <fstream>
#include <string>
#include "Maxheap.h"

namespace EC504project {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// MyForm 摘要
	/// </summary>
	
	vector<int> Ncount;
	vector<string> tweets;
	string tweet;
	string pattern = "";
	string query;

	int KMPsearch(string text, string pattern);
	void computeprefix(string pattern, int m, int* prefix);
	std::string ConvertToString(System::String^ str);


	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO:  在此处添加构造函数代码
			
			//
		}

	protected:
		/// <summary>
		/// 清理所有正在使用的资源。
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;

	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ button1;


	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::Label^ label13;

	protected:

	private:
		/// <summary>
		/// 必需的设计器变量。
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 设计器支持所需的方法 - 不要修改
		/// 使用代码编辑器修改此方法的内容。
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Segoe Script", 15.85714F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(512, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(467, 61);
			this->label1->TabIndex = 0;
			this->label1->Text = L"TwitterKeywordSearch";
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(1, -2);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(75, 75);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 2;
			this->pictureBox1->TabStop = false;
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->Location = System::Drawing::Point(216, 73);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(1049, 32);
			this->textBox1->TabIndex = 3;
			this->textBox1->Text = L"Enter the keywords you want and seperate them with spaces";
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::SystemColors::InactiveCaption;
			this->button1->ForeColor = System::Drawing::SystemColors::ControlText;
			this->button1->Location = System::Drawing::Point(651, 130);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(142, 59);
			this->button1->TabIndex = 4;
			this->button1->Text = L"Search";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Californian FB", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(598, 207);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(238, 24);
			this->label3->TabIndex = 7;
			this->label3->Text = L"Top 10 most similar tweets";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Californian FB", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(43, 245);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(70, 24);
			this->label4->TabIndex = 8;
			this->label4->Text = L"tweet 1";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Californian FB", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(43, 282);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(73, 24);
			this->label5->TabIndex = 9;
			this->label5->Text = L"tweet 2";
			this->label5->Click += gcnew System::EventHandler(this, &MyForm::label5_Click);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Californian FB", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(43, 315);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(72, 24);
			this->label6->TabIndex = 10;
			this->label6->Text = L"tweet 3";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Californian FB", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->Location = System::Drawing::Point(43, 348);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(74, 24);
			this->label7->TabIndex = 11;
			this->label7->Text = L"tweet 4";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Californian FB", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->Location = System::Drawing::Point(43, 381);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(72, 24);
			this->label8->TabIndex = 12;
			this->label8->Text = L"tweet 5";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Californian FB", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label9->Location = System::Drawing::Point(43, 415);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(73, 24);
			this->label9->TabIndex = 13;
			this->label9->Text = L"tweet 6";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Californian FB", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label10->Location = System::Drawing::Point(43, 449);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(71, 24);
			this->label10->TabIndex = 14;
			this->label10->Text = L"tweet 7";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"Californian FB", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label11->Location = System::Drawing::Point(43, 484);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(71, 24);
			this->label11->TabIndex = 15;
			this->label11->Text = L"tweet 8";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Font = (gcnew System::Drawing::Font(L"Californian FB", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label12->Location = System::Drawing::Point(43, 518);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(73, 24);
			this->label12->TabIndex = 16;
			this->label12->Text = L"tweet 9";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Font = (gcnew System::Drawing::Font(L"Californian FB", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label13->Location = System::Drawing::Point(43, 552);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(81, 24);
			this->label13->TabIndex = 17;
			this->label13->Text = L"tweet 10";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(11, 21);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1447, 597);
			this->Controls->Add(this->label13);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm";
			this->Text = L"TwitterKeywordSearch";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label5_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	tweets.clear();
	Ncount.clear();
	ifstream infile;
	infile.open("SampleInputForProject.txt");
	while (getline(infile, tweet)) { // read in the tweets
		tweets.push_back(tweet);
		Ncount.push_back(0);
	}
	infile.close();
}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	tweets.clear();
	Ncount.clear();
	ifstream infile;
	infile.open("SampleInputForProject.txt");
	while (getline(infile, tweet)) { // read in the tweets
		if (tweet.empty()) {
			continue;
		}
		tweets.push_back(tweet);
		Ncount.push_back(0);
	}
	infile.close();
	String^ keyword = textBox1->Text;
	query = ConvertToString(keyword);
	for (int i = 0; i <= query.size(); i++) { //split the queryuntil pattern is null
		if (query[i] == ' ' || query[i] == '\0') {
			for (int j = 0; j < Ncount.size(); j++) {
				Ncount[j] += KMPsearch(tweets[j], pattern);
			}
			pattern = "";
		}
		else pattern += query[i];
	}

	PriorityQueue Mheap; // Max heap
	Mheap.initize(Ncount);

	int k = 0;
	string out;
	if (k != 10) {
		if (!Mheap.isEmpty()) {
			out = tweets[Mheap.pop()];
			String^ temp = gcnew String(out.c_str());
			label4->Text = temp;
			k++;
		}
	}
	if (k != 10) {
		if (!Mheap.isEmpty()) {
			out = tweets[Mheap.pop()];
			String^ temp = gcnew String(out.c_str());
			label5->Text = temp;
			k++;
		}
	}
	if (k != 10) {
		if (!Mheap.isEmpty()) {
			out = tweets[Mheap.pop()];
			String^ temp = gcnew String(out.c_str());
			label6->Text = temp;
			k++;
		}
	}
	if (k != 10) {
		if (!Mheap.isEmpty()) {
			out = tweets[Mheap.pop()];
			String^ temp = gcnew String(out.c_str());
			label7->Text = temp;
			k++;
		}
	}
	if (k != 10) {
		if (!Mheap.isEmpty()) {
			out = tweets[Mheap.pop()];
			String^ temp = gcnew String(out.c_str());
			label8->Text = temp;
			k++;
		}
	}
	if (k != 10) {
		if (!Mheap.isEmpty()) {
			out = tweets[Mheap.pop()];
			String^ temp = gcnew String(out.c_str());
			label9->Text = temp;
			k++;
		}
	}
	if (k != 10) {
		if (!Mheap.isEmpty()) {
			out = tweets[Mheap.pop()];
			String^ temp = gcnew String(out.c_str());
			label10->Text = temp;
			k++;
		}
	}
	if (k != 10) {
		if (!Mheap.isEmpty()) {
			out = tweets[Mheap.pop()];
			String^ temp = gcnew String(out.c_str());
			label11->Text = temp;
			k++;
		}
	}
	if (k != 10) {
		if (!Mheap.isEmpty()) {
			out = tweets[Mheap.pop()];
			String^ temp = gcnew String(out.c_str());
			label12->Text = temp;
			k++;
		}
	}
	if (k != 10) {
		if (!Mheap.isEmpty()) {
			out = tweets[Mheap.pop()];
			String^ temp = gcnew String(out.c_str());
			label13->Text = temp;
			k++;
		}
	}
}
};


int KMPsearch(string text, string pattern) {
	int n = text.size(); // read the length of pattern and text
	int m = pattern.size();
	int* prefix= new int[m]; // prefix table's length equal to length of the pattern

	computeprefix(pattern, m, prefix); // precompute the prefix table

	int i = 0;//start to do the pattern search
	int j = 0;
	int count = 0;//count the number of patterns found

	while (i < n) {
		if (text[i] == pattern[j]) { // if a letter match, go to the next letter for both array
			i++;
			j++;
		}

		if (j == m) {//if j exceed the last letter of the pattern, pattern found and go to the index referred by the prefix array
			count++;
			j = prefix[j - 1];
		}

		else if (text[i] != pattern[j] && i < n) {
			if (j != 0) j = prefix[j - 1]; // if not match, go to the index referred by the prefix array
			else i++; // if j=0; then i increments by 1
		}
	}
	return count;
}

void computeprefix(string pattern, int m, int* prefix) {
	int len = 0; //length of the longest prefix suffix from the previous index

	prefix[0] = 0; //prefix array indexed at 0 is always set to 0

	int i = 1; //start to compute
	while (i < m) {
		if (pattern[i] == pattern[len]) { // length of longest prefix suffix++ if the next letter matches the letter indexed at len+1
			len++;
			prefix[i] = len;
			i++;
		}
		else {
			if (len != 0) len = prefix[len - 1]; // if not match, trace back len from the prefix array
			else {
				prefix[i] = 0; // if not match then set it to 0 and continue working on the prefix array
				i++;
			}
		}
	}

}

std::string ConvertToString(System::String^ str)
{
	int q = (int)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(str);
	char* p = (char*)q;
	return std::string(p);
}

}
