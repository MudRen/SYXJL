
// Room: /jingzhou/xiaoshitan.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "Сʳ̯");
        set("long", @LONG
�˵���������С��̯�Ӻܶ࣬����ʳƷ���ú�����ɫ��ζ��Ҳ�ܲ���
���������ܶ��˶������ﳢ���ʡ��ϰ��������ޣ���˵����������Բ������
���ԳƵ���һ���ˡ�
LONG
        );
//        set("outdoors", "jingzhou");
        set("exits", ([
                "north" : __DIR__"quyuanlu2",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}