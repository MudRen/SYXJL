
// Room: /jingzhou/datiepu.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
��һ�߽����͸е�������ȡ�ԭ������һ�Ҽ�ª�Ĵ����̣����İ���
һ����¯��¯��������յ�һƬͨ�죬ǽ�Ƕ������Ѿ��깤��δ�깤�Ĳ�
�����������������λ����������ͷ�󺹻�����������ר����־����
������
LONG
        );
//        set("outdoors", "jingzhou");
        set("exits", ([
                "south" : __DIR__"jingnanlu2",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}