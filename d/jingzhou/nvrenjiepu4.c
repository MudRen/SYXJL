
// Room: /jingzhou/nvrenjiepu4.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "Ů�˽ֵ���");
        set("long", @LONG
����������Щ��ɫ˿��ͽ��У�����һЩ���꣬ˮ���ȵȹ��ص�ëƤ��
�ܶ��ٸ��͹��ﶼ͵͵��һЩ��ȥ�����˸��Լ����ɷ���������������
���ѡ�
LONG
        );
//        set("outdoors", "jingzhou");
        set("exits", ([
                "north" : __DIR__"nvrenjie1",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}