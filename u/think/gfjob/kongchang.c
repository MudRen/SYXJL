inherit ROOM;

void create()
{
        set("short", "�㳡");
        set("long", @LONG
����֪���Աߵ�һƬС�ճ����ڶ��ߵ�ǽ�����˼��Źٸ�����׽�ó�͢
Ҫ���ĸ�ʾ������Χ������࿴���ֵ��ˣ����в���һЩ���ָ��֣���
��Ҫ׽�õ�Ҫ���������֣������������Ұ�jie wenshu��,��Ҳ�в�
�����ֺ���֮����һ��ԾԾ���ԡ�
LONG
        );

        set("exits", ([
                 "southwest" : "/d/city/yamen",
                 
        ]));
        set("objects", ([
                "/quest/gfjob/npc/yayi" : 1,
        ]));
         
        setup();
}
#include "/quest/gfjob/job2.h"


