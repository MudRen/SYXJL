
// Room: /chang'an/diyilou.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "��һ¥");
        set("long", @LONG
��������û�в�֪������һ¥���ġ���������������Ҫ�壬��������
�࣬���̴���Ƽ�����������ǳ���¡��¥�²������Ҫ����һЩ���˿�
���ǴҴҵ����ˣ��������������ȡ��ƴ��͸�·ȥ�ˡ�¥����������
LONG
        );
        set("outdoors", "chang'an");
        set("exits", ([
                "south" : __DIR__"dongdajie1",
                "up"    : __DIR__"diyilouerlou",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}