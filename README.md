My_RPG
This project is one of the freest project of your first year. Create your own RPG.
Your main challenge for this game will be to create a complete product using everything that you and your
team know.

We had the best grade of the promotion, a guarantee of quality trophy

Description sunrise_over_mountains
Your game must follow the following rules:
      • The player needs to have characteristics which you can find in the status menu.
      • The player can fight enemies, statistics will impact the fights results.
      • There must be NPC in your game.
      • You need to implement at least one quest.
      • The player must have an inventory which can contain a limited set of items.
      • The player can earn experience by winning fights and accomplishing specific actions.
      • With enough experience, the player can level up, upgrading its statistics.

To realize our project, we were only allowed to use some functions,
most of them being forbidden such as: printf




We started with the creation of a game engine,
that is to say that we created functions allowing to add buttons, particle generators, animated texts...
as simply as possible to save time later.
You just have to call the function and the new object will be stored after the linked list of its type




Another important part, is the creation of a JSON parser and writer.
We were obviously not allowed to use what already exists, so we remade a JSON parser
which you will see will be useful later on.

The parser is integrated in the project sources or available alone on this repository

ReadMe Card


Then, after preparing our game engine, we made a scene system that fades at each scene change,
then we focused on the menu, a smooth interface, intuitive, buttons that have pixel accurate hitboxes.
This is what we wanted and what we did.
