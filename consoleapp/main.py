import gi
gi.require_version("Gtk", "4.0")
from gi.repository import Gtk, Gdk
import subprocess
import os
import threading
import pygame
import pyautogui
import time
SCREEN_WIDTH, SCREEN_HEIGHT = pyautogui.size() 
MOUSE_SPEED = 15 # pixels per frame
JOYSTICK_DEADZONE = 0.1 # Ignore small movements near the center


class FullscreenApp(Gtk.Application):

    
    def on_click_event(self, gesture, n_press, x, y):
        # 'gesture' is a Gtk.Gesture object
        # The event widget is the one the gesture controller is attached to
        event_widget = self.gesture.get_widget()

        # Use the pick method to find the child widget at the coordinates
        # Gtk.PickFlags.DEFAULT is used here, or you could use Gtk.PickFlags.INSENSITIVE etc.
        child_widget = event_widget.pick(x, y, Gtk.PickFlags.DEFAULT)
        #print(dir(child_widget))
        if child_widget:
            print(f"Clicked on child widget of type: {type(child_widget).__name__}")
            clicked_button = child_widget.get_ancestor(Gtk.Button)
            clicked_button.emit('clicked')

            #.activate_action('clicked', child_widget.parent_instance())
            # You can now operate on the specific child_widget
    
    def __init__(self):
        super().__init__(application_id="org.example.FullscreenApp")
        self.connect("activate", self.on_activate)
        self.running =  True
        self.gesture = Gtk.GestureClick.new()
        
    def activate_gtk_button(self, x,y):
        print("GTK will activate button")
        self.on_click_event(self.gesture, 1, x,y)
        #print(gtk_widget_pick(self, 0, 0))
        
    def on_activate(self, app):
        self.running = True
        # Create a new application window
        self.window = Gtk.ApplicationWindow(application=app, title="Aaryans's Game Console")
        main_box = Gtk.Box(orientation=Gtk.Orientation.VERTICAL, spacing=10)
        # Make the window fullscreen
        #self.gesture = Gtk.GestureClick.new()
        self.gesture = Gtk.GestureClick.new()
        self.gesture.connect("pressed", self.on_click_event)
        self.window.add_controller(self.gesture)

        main_box  = Gtk.Grid()
        self.window.fullscreen()

        # Add content to the window (optional)
        label = Gtk.Label(label="Select a game to play")
        #self.window.add_child(label)

        self.window.set_child(main_box)
        #print(dir(self.window))


        buttonPong = Gtk.Button(label="Pong with Joy")
        buttonPong.connect("clicked", self.on_button_clicked)

        dirs = os.listdir("/home/aaryan/Desktop/Games")
        dirlen =  len(dirs)
        rowcount = 0
        for index in range(0, dirlen, 2):
            buttonPong = Gtk.Button(label=dirs[index])
            buttonPong.connect("clicked", self.on_button_clicked)
            image = Gtk.Image(file= "/home/aaryan/git/gamecode/consoleapp/"+dirs[index]+'.png');
            buttonPong.set_child(image);
            buttonPong.set_size_request(200, 100)
            buttonPong._value = dirs[index]

            if index+1 < dirlen:
                buttonPong1 = Gtk.Button(label=dirs[index+1])
                buttonPong1.connect("clicked", self.on_button_clicked)
                image = Gtk.Image(file= "/home/aaryan/git/gamecode/consoleapp/"+dirs[index+1]+'.png');
                buttonPong1.set_size_request(200, 100)
                buttonPong1.set_child(image);
                
                buttonPong1._value = dirs[index+1]
            
            main_box.attach(buttonPong,  index/2, 0, 1, 1) # Col 0, Row 0, spans 1 col and 1 row
            if index+1 < dirlen:
                main_box.attach(buttonPong1, index/2, 1, 1, 1) # Col 1, Row 0
            #main_box.attach(buttonPong, 0, 1, 1, 1) # Col 0, Row 1
            #main_box.attach(buttonPong, 1, 1, 1, 1) # Col 1, Row 1

        # Add spacing between elements
        main_box.set_column_spacing(5)
        main_box.set_row_spacing(5)

        
        #main_box.append(label)
        #main_box.append(buttonPong)
        

        

        # Connect the "Escape" key press to exit fullscreen
        # We need a controller to handle keyboard events
        key_controller = Gtk.EventControllerKey()


        


        key_controller.connect("key-pressed", self.on_key_pressed)

        
        self.window.add_controller(key_controller)

        # Present the window to the user
        self.window.present()

    def on_button_clicked(self, widget):
        try:
            result = subprocess.run(["cd /home/aaryan/Desktop/Games/{}/ && ./{}".format(widget._value,widget._value)], capture_output=True, text=True, check=True, shell=True) #
            print(result.stdout)
        except subprocess.CalledProcessError as e:
            print(f"Command failed with error: {e.stderr}")

    
    def on_key_pressed(self, controller, keyval, keycode, state):
        # Check if the pressed key is the 'Escape' key (Gdk.KEY_Escape)
        if keyval == Gdk.KEY_Escape:
            if self.window.is_fullscreen():
                self.window.unfullscreen()
            return True # Event handled

        return False # Event not handled

def joystick_handler(app):
    pygame.init()
    pygame.joystick.init()

    if pygame.joystick.get_count() == 0:
        print("No joystick found. Exiting joystick thread.")
        app.running = False
        return

    joystick = pygame.joystick.Joystick(0)
    joystick.init()
    print(f"Initialized Joystick: {joystick.get_name()}")

    try:
        print('app val', app.running)
        while True:
        # Process Pygame events
            """
            for event in pygame.event.get():
                if event.type == pygame.QUIT:
                    pygame.quit()
                    sys.exit()
                    # 1. Check for a joystick button pres
                elif event.type == pygame.JOYBUTTONDOWN:
                    # Assuming button 0 (often 'A' or 'X' on controllers) is the desired button
                    if event.button == 0: 
                        print("Joystick button 0 pressed, simulating Enter key.")

                        # 2. Create and post a new KEYDOWN event for the Enter key (K_RETURN)
                        enter_event = pygame.event.Event(pygame.KEYDOWN, unicode="\r", key=pygame.K_RETURN, mod=pygame.KMOD_NONE)
                        pygame.event.post(enter_event)

                        # 3. Handle the 'simulated' Enter key event like any other keyboard event
                    elif event.type == pygame.KEYDOWN:
                        if event.key == pygame.K_RETURN:
                            print("Enter key (physical or simulated) was detected in the event loop!")
            """
                    # Get joystick axis values
                    # Axis 0 is typically horizontal movement (left=-1, right=1)
                    # Axis 1 is typically vertical movement (up=-1, down=1)
                    # Note: Axis mapping can vary by controller
            horiz_move = joystick.get_axis(0)
            vert_move = joystick.get_axis(1)

            # Apply deadzone logic to prevent "drift"
            if abs(horiz_move) < JOYSTICK_DEADZONE:
                horiz_move = 0
            if abs(vert_move) < JOYSTICK_DEADZONE:
                vert_move = 0
            
                # Calculate new mouse position
                # PyAutoGUI handles the system-level cursor movement
            current_x, current_y = pyautogui.position()
            new_x = current_x + horiz_move * MOUSE_SPEED
            new_y = current_y + vert_move * MOUSE_SPEED

            # Set the system mouse position
            pyautogui.moveTo(new_x, new_y)

            # Add a small delay to control the speed of the loop and CPU usage
            pygame.time.wait(10) 


            for event in pygame.event.get():
                if event.type == pygame.JOYBUTTONDOWN:
                    print(f"Joystick button {event.button} pressed.")
                    # Assuming button 0 is the one you want to map
                    if event.button == 0:
                        app.activate_gtk_button(new_x, new_y)
            # Small sleep to prevent burning CPU cycles
            time.sleep(0.01)

            
    except pygame.error as e:
        print(f"Joystick error: {e}")
    finally:
        pygame.joystick.quit()
        pygame.quit()
    
def main():
    app = FullscreenApp()


    joy_thread = threading.Thread(target=joystick_handler, args=(app,), daemon=True)
    joy_thread.start()

    # Run the GTK main loop
    #Gtk.main()

    # Stop the joystick thread when the GTK window is closed
    app.running = False
    
    app.run(None)
    joy_thread.join()

if __name__ == "__main__":
    main()

