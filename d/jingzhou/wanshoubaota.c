
// Room: /jingzhou/wanshoubaota.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "���ٱ���");
        set("long", @LONG
�����޽�������ԭ������ˮ֮�á����������̰������������ƣ�������
һ��Ƭ������֣���ʹ����Ҳ������ϰϰ������һƬ��ã�һ������οͶ�
Ҫ��������һ�¡���˵����Ľ��ڲ���ǰ��̫���ױ�����ġ���վ�����
LONG
        );
        set("outdoors", "jingzhou");
        set("exits", ([
                "up"  : __DIR__"tading",
                "west"  : __DIR__"dukou",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}