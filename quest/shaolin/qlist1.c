#include <ansi.h>

inherit SKILL;

mapping *quest = ({
        ([      "quest":               "�������䵶",
                "quest_type":           "Ѱ",
                "time":                 600,
                "score" :               6
        ]),
        ([      "quest":                "��ľ��",
                "quest_type":           "Ѱ",
                "time":                 200,
                "score" :               3
        ]),
         ([      "quest":               "�ۺ����",
                "quest_type":           "Ѱ",
                "time":                 600,
                "score" :               6
        ]),
        ([      "quest":                "������",
                "quest_type":           "Ѱ",
                "time":                 200,
                "score" :               3
        ]),
 	
        ([      "quest":               "ά����峤��",
                "quest_type":           "Ѱ",
                "time":                 600,
                "score" :               6
        ]),
        ([      "quest":                "������",
                "quest_type":           "Ѱ",
                "time":                 200,
                "score" :               3
        ]),
 	
        ([      "quest":                "�йٱ�",
                "quest_type":           "Ѱ",
                "time":                 600,
                "score" :               6
        ]),
        ([      "quest":                "ʴ����",
                "quest_type":           "Ѱ",
                "time":                 200,
                "score" :               3
        ]),
        ([      "quest":                "���",
                "quest_type":           "Ѱ",
                "time":                 200,
                "score" :               3
        ]),       
        ([      "quest":                "�ߵ���",
                "quest_type":           "Ѱ",
                "time":                 200,
                "score" :               3
        ]),                      	
        ([      "quest":		"����",               
                "quest_type":           "Ѱ",
                "time":  		300,
                "score"	:		6,
                "reason" :              "�������������ʦ˵��������Ҫ�����������壬"
        ]),
        ([      "quest":                "�ֽ�",
                "quest_type":           "Ѱ",
                "time":                 360,
                "score" :               6,
                "reason" :              "�������������ʦ˵��������Ҫһ���ֽ�������������"
        ]),
        ([      "quest":                "�����",
                "quest_type":           "Ѱ",
                "time":                 400,
                "score" :               5,
                "reason" :              "�����ֱ޷��侫�������ڳ��޵�������\nȴ���У�������ʦ˵��Ҫһ�����������壬\n"
        ]),
        ([      "quest":                "ˮ����",
                "quest_type":           "Ѱ",
                "time":                 400,
                "score" :               3,
                "reason" :              "��������ˮ���ҳ���ļ��ڣ�ҩƷ�������ʦ��ʦҪ����ҩ�\n"
        ]),
        ([      "quest":                "��ɽ����",
                "quest_type":           "Ѱ",
                "time":                 450,
                "score" :               5,
                "season" :              "Ϊ�����ڼ�֮�������뿴����ɽ�Ľ�����"
        ]),       
        ([      "quest":                "������",
                "quest_type":           "Ѱ",
                "time":                 450,
                "score" :               5
        ]),  
        ([      "quest":                "ʯ��",
                "quest_type":           "Ѱ",
                "time":                 480,
                "score" :               7,
                "reason" :              "�����ּ�����ѧ������ʯ�岻���ˣ�"
        ]),
    ([      "quest":                "�㳡",
                "quest_type":           "ɨ",
                "time":                 410,
                "score" :               6,
                "reason" :              "���ڹ㳡û���˴�ɨ��"
        ]),
        ([      "quest":                "���޳�",
                "quest_type":           "ɨ",
                "time":                 410,
                "score" :               6,
                "reason" :              "��˵���޳����ڱȽ��࣬"
        ]),
        ([      "quest":                "�����",
                "quest_type":           "ɨ",
                "time":                 410,
                "score" :               6,
                "reason" :              "��˵��������ڱȽ��࣬"
        ]),


           
});


mapping query_quest()
{
        return quest[random(sizeof(quest))];
}
