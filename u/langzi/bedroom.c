inherit ROOM;

void create()
{
        set("short","���������");
        set("long",@LONG
�������ӹ��ѵ�����ң�����һ��ҡҡ�λε��ƴ���
LONG
        );
        set("exits",([
                "west" : __DIR__"workroom",
                "out" : "/d/city/wumiao",
        ]));
        set("sleep_room", 1);
        set("no_fight", 0);

        setup();
}

