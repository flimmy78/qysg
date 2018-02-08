#pragma once
#include "afxwin.h"

#pragma pack(1)
struct GameAcc{
	CString account;
	CString password;
	CString password2;
	CString duedate;
	CString enable;
	CString lock_duedate;
	CString logout_time;
	CString ip;
	CString create_time;
	CString privilege;
	CString status;   //״̬
	CString sec_pwd;
	CString first_ip;
	CString point;
	CString trade_psw;
	CString IsAdult;
	CString OnlineTime;
	CString OfflineTime;
	CString LastLoginTime;
	CString LastLogoutTime;
};
#pragma pack() 

#pragma pack(1)
struct SoldierAttr
{
	char type[2];    //ò�������Ļ��ǻ����˼��ֻ������1 �� 0��ֵ
	char Name[16];		// ����
	char A1[3]; // ��ֵ���ǲ�֪����ʲô
	unsigned __int16 Level;
	unsigned __int32 Hp;
	unsigned __int32 Exp;
	char A2[16]; // ��ֵ���ǲ�֪����ʲô
	unsigned __int16 Attr_str; //����
	unsigned __int16 Attr_int;//����
	unsigned __int16 Type;//����
	unsigned __int16 Attr_dex;//����
	unsigned __int16 Attr_mind; //��Ӧ
	
	char A3[58]; // ��ֵ���ǲ�֪����ʲô
	unsigned __int8 Loyal; //�ҳ�
	char A4[3]; // ��ֵ���ǲ�֪����ʲô
	unsigned __int8 Attack;//����������
	unsigned __int8 Defence;//����������
	char A5[22]; // ��ֵ
};
#pragma pack() 

#pragma pack(1)
struct AccAttr
{
	char Account[24];  // �����ʺ�
	char A1[4];
	unsigned __int32 nIndex;	// ���
	char Name[15];		// ����
	char Corps[15];		//����
	unsigned __int32 Gold;		//��Ǯ
	unsigned __int32 Exp;
	unsigned __int16 SkillExp;
	unsigned __int16 Anger;
	unsigned __int16 AngerNum;
	unsigned __int16 Level;
	char A2[7];
	unsigned __int16 Attr_Num;  //���Ե�
	unsigned __int32 Honor;	//��ѫֵ
	unsigned __int32 Hp;
	unsigned __int32 Mp;

	char A3[249];

	unsigned __int16 Attr_str_up;   // ��������
	unsigned __int16 Attr_int_up;
	unsigned __int16 Attr_con_up;
	unsigned __int16 Attr_dex_up;
	unsigned __int16 Attr_mind_up;
	unsigned __int16 Attr_leader_up;

	unsigned __int16 Attr_str; //����
	unsigned __int16 Attr_int;//����
	unsigned __int16 Attr_con;//����	
	unsigned __int16 Attr_dex;//����
	unsigned __int16 Attr_mind; //��Ӧ	
	unsigned __int16 Attr_leader;//ͳ��

	char A4[979];

	unsigned __int8 PackNum;//��������		
	unsigned __int8 StoreNum; //�ֿ����

	char A5[169];

	unsigned __int16 Officer;	//��ְ

	char A6[232];
};
#pragma pack() 

#pragma pack(1)
struct OrganizeAttr
{
	char A1[2312]; // ��ֵ
	char A2[8]; // ��ֵ����;δ֪
	char A3[6]; // ��ֵ
	unsigned __int16  StageId; // ���д���
	char A4[4]; // ��ֵ����;δ֪
	char OrganizeLeader[15]; // ���ų�
	char A5[4]; // ��ֵ����;δ֪
	char A6[8]; // ��ֵ����;δ֪

	char A7[1473]; // ��ֵ
	char A8[2]; // ��ֵ����;δ֪
	char A9[7]; //��ֵ
	char OrganizeName[15]; //������
	char OrganizeLeaderZh[15]; //�ų�
	char OrganizeLeaderFu[15]; //����
	char A10[2]; //�²�Ϊ��Ա����
	char A11[9]; // ��ֵ����;δ֪

	char A12[519]; // ��ֵ
};
#pragma pack()

#pragma pack(1)
struct ItemDef{
	CString ID;
	CString Name;
};
#pragma pack() 

#pragma pack(1)
struct StageDef{
	CString ID;
	CString Name;
};
#pragma pack() 

#pragma pack(1)
struct CwarHeroes
{
	CString Name;	// ��ɫ��
	CString Level;	// �ȼ�
	CString Job;	// ְҵ
	CString Nationality;	// ����
	CString Honor;	// ��ѫֵ
	CString Kills;	// �ֵ���
	CString Corps;
};
#pragma pack() 

#pragma pack(1)
struct CwarCorps
{
	char Name[15];	// ������
	char ID[15];	// Ψһ��ʶ
	unsigned __int16 Honor;	// ��ѫ��
};
#pragma pack() 

#pragma pack(1)
struct HistoryCbHeroes
{
	CString Account;	// ��ɫ�ʺ�
	CString Name;	// ��ɫ��
	CString Job;	// ְҵ
	CString Nationality;	// ����
	CString Points;	// ����
	CString Honor;	// ��ѫֵ
	CString Kills;	// �ֵ���
};
#pragma pack() 

#pragma pack(1)
struct ServerConfigTime
{
	CString Period;  // ����ʱ��
	CStringArray ModStartTimes;
	CStringArray TuseStartTimes;
	CStringArray WedStartTimes;
	CStringArray ThursStartTimes;
	CStringArray FriStartTimes;
	CStringArray SatStartTimes;
	CStringArray SunStartTimes;
};
#pragma pack()

#pragma pack(1)
struct CwarAwards
{
	CString OrganizeName;  // ������
	CString OrganizeNameOfLeaderZh; //�ų�
	CString OrganizeAccountOfLeaderZh; //�ų��ʺ�
	CString StageName;
	CString StageID;
	unsigned int AwardsTimes;
};
#pragma pack()

#pragma pack(1)
struct SaveItem
{
	unsigned __int32 TimeStamp; // ��1970�굽�����ص�����
	char A1[4];  // ��Ʒ�����ǵı�Ǻţ��ӷ�����������ʼ����
	char PlayerName[15];  // ��ɫ��
	char A2[2];
	unsigned __int16 ItemId;
	char A3[4];
	unsigned __int8 ItemNum;
	char A4[40];
};
#pragma pack()

#pragma pack(1)
struct SaveItems
{
	struct SaveItem Player_1[80];  // ��һ����ɫ����Ʒ
	struct SaveItem Player_2[80];  // �ڶ�����ɫ����Ʒ
	struct SaveItem Player_3[80];  // ��������ɫ����Ʒ
};
#pragma pack()

#pragma pack(1)
struct SaveStore
{
	unsigned __int32 TimeStamp; // ��1970�굽�����ص�����
	char A1[4];  // ��Ʒ�����ǵı�Ǻţ��ӷ�����������ʼ����
	char PlayerName[15];  // ��ɫ��
	char A2[2];
	unsigned __int16 ItemId;
	char A3[4];
	unsigned __int8 ItemNum;
	char A4[40];
};
#pragma pack()

#pragma pack(1)
struct SaveStores
{
	unsigned __int32 Player_1_Money;  // ���
	struct SaveStore Player_1[104];  // ��һ����ɫ����Ʒ
	char A1[8];   // 8���ֽڲ�֪���Ǹ���ģ� �Ǻ�

	unsigned __int32 Player_2_Money;  // ���
	struct SaveStore Player_2[104];  // �ڶ�����ɫ����Ʒ
	char A2[8];   // 8���ֽڲ�֪���Ǹ���ģ� �Ǻ�

	unsigned __int32 Player_3_Money;  // ���
	struct SaveStore Player_3[104];  // ��������ɫ����Ʒ
	char A3[8];   // 8���ֽڲ�֪���Ǹ���ģ� �Ǻ�
	
};
#pragma pack()