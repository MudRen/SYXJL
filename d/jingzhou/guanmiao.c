inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
������Ƴ�����Ǿ��ݰ�����Ϊ�羴�������ˣ��������ݵĹ�������
�������Ľ�������ȥ�Ϳ��Կ����ض�ү������������ֳ�����۱�µ���
�֣ܲ��ұ߷������ӡ�Ĺ�ƽ��ǰ�������󸣵���Ҳ���٣��ļ���𲻾���
��ǰ�Ĺ㳡����������������������ˣ��ħ��֮��ı�����������ַ�
����
LONG
        );        
//        set("outdoors", "jingzhou");
        set("exits", ([
                "west"  : __DIR__"nanmendajie2",
        ]));
        set("no_fight", "1");
        set("no_steal", "1");
        set("no_sleep_room", "1");
        set("no_study", "1");
        set("no_kill",1);
        set("no_yun",1);
        set("no_beg",1);
        set("no_hit",1);
        set("no_array",1);
        set("no_clean_up", 0);
        set("objects", ([
                "/d/city/obj/box" : 1,
                ]));
        setup();
        replace_program(ROOM);
}

