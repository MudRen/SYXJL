inherit ROOM;
void create()
{
        set("short", "车厢内");
        set("long", @LONG
车里干干净净，放了两张舒服的大椅子。窗帘拉了下来，阳光从缝隙中透
进来，不知道车子走到哪里了。门外挂了一串风铃，叮呤呤响着。车夫坐在前
面，一路赶着马，一路得意地哼着什么小调
LONG
        );

        setup();
}
void run(object ob)
{
        if (environment(ob) == this_object())
        ob->move(__DIR__"che38", 1);
        write("\n车夫扬起马鞭“啪”地甩了一下，大车轰隆隆地开了起来。。。\n\n");
}

void init()
{
       object ob = this_player();

    call_out("run", 3, ob);
}
