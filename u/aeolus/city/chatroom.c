inherit ROOM;

void create()
{
        set("short", "���̨");
    set("long",@LONG 
һ������㷢���������ڲ�ͬ��һ�ж�����ɫ�ģ����صĴ���������
�����һ�У�����Ļ�������������Ŀ��һ�ֻص��ñ����ĸо���Ȼ��
�������Ƕ���һ���������һ�ݳ�Թ�������Ѷ����ģ������˶�۾ۣ�Ϊ
����������һ����Ȥ��һ�ݷ��ǡ�
LONG
);

        set("exits", ([
                "out" : "/d/city/kedian",
        ]));

        set("objects", ([
               "/u/yanzi/bingqipu" : 1,
                "/adm/daemons/topten/bang" : 1,
        ]));

        set("no_fight",1);
        set("no_hit",1);
        set("no_array",1);
        set("no_sleep_room",1);
        set("no_kill",1);
        set("no_steal",1);
        set("no_yun",1);
        set("no_beg",1);
        setup();
        replace_program(ROOM);
}

