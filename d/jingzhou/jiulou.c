
// Room: /jingzhou/jiulou.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "��¥");
        set("long", @LONG
�ڴ˵�������ʨ��¥����˵�����˲�֪�����˲��������ǿ����˼�����
�ľƲ��Ѿ�����ʳָ���ˣ�ʵ�����˰��Ͳ�ס�Լ���ʳ����ȥ����һ����
������ɫ�˲źá�¥�²������Ҫ��һЩ���˿Ͷ�����ͨ���ա�¥������
��������ļ��������Ĺ��Ӹ���������춼Ҫ�������������֡�
LONG
        );
//        set("outdoors", "jingzhou");
        set("exits", ([
                "up"  : __DIR__"jiulouerlou",
                "west"  : __DIR__"sanyijie2",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}