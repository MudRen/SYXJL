inherit ROOM;
void create()
{
        set("short", "车厢内");
        set("long", @LONG
你坐在马车里，浑然不知外面的情景。马车晃晃悠悠，停停走走，不知过了多少天……
LONG
        );

        setup();
}
void run(object ob)
{
        ob = this_player();
        if (environment(ob) == this_object())
	message_vision("\n两匹马拉着一乘大车跑了过来，车夫一声吆喝，马车停了下来。\n",ob);        
	message_vision("\n车夫大声说：“到啦，这里就是万梅山庄。”随即掀开车门。\n",ob);   
	message_vision("\n$N从车上走了下来。\n",ob);	   		
        ob->move("/u/smok/village", 1);
}

void init()
{
       object ob = this_player();

    call_out("run", 10, ob);
}
