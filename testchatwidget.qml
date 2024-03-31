import QtQuick 2.15
import QtTest 1.2

Item {
    property var chatItemWidget: null

    Component.onCompleted: {
        initMocks();
    }

    function initMocks() {
        chatItemWidget = createChatItemWidget();
    }

    function createChatItemWidget() {
           return {
               message: "",
               timestamp: "",
               isMyMessage: false,
               setMessage: function(message, isMyMessage) {
                   this.message = message;
                   this.isMyMessage = isMyMessage;
                   this.timestamp = new Date().toString();
               }
           };
    }

    TestCase {
        name: "testSetMessage"

        function test_testSetMessageUT11() {
            console.log("Running testSetMessage");
            var message = "Test message";
            var isMyMessage = true;
            var chatItemWidget = createChatItemWidget();
            chatItemWidget.setMessage(message, isMyMessage);
            console.log("Message set to:", chatItemWidget.message);
            console.log("isMyMessage set to:", chatItemWidget.isMyMessage);
            verify(chatItemWidget.message === message);
            verify(chatItemWidget.isMyMessage === isMyMessage);
            console.log("TestSetMessage executed successfully");
        }

        function test_testTimestampSetForMessageUT10() {
            console.log("Running testTimestampSetForMessage");
            var message = "Test message";
            var isMyMessage = true;
            var chatItemWidget = createChatItemWidget();
            chatItemWidget.setMessage(message, isMyMessage);
            verify(chatItemWidget.timestamp !== "");
            console.log("Timestamp set to:", chatItemWidget.timestamp);
        }

        function test_testSetMessageAdditional1() {
                  console.log("Running testSetMessage for non-My Message");
                  var message = "Test message";
                  var isMyMessage = false;
                  var chatItemWidget = createChatItemWidget();
                  chatItemWidget.setMessage(message, isMyMessage);
                  console.log("Message set to:", chatItemWidget.message);
                  console.log("isMyMessage set to:", chatItemWidget.isMyMessage);
                  verify(chatItemWidget.message === message);
                  verify(chatItemWidget.isMyMessage === isMyMessage);
                  console.log("TestSetMessage executed successfully for non-My Message");
              }

              function test_testSetMessageAdditional2() {
                  console.log("Running testSetMessage with empty message");
                  var message = "";
                  var isMyMessage = true;
                  var chatItemWidget = createChatItemWidget();
                  chatItemWidget.setMessage(message, isMyMessage);
                  console.log("Message set to:", chatItemWidget.message);
                  console.log("isMyMessage set to:", chatItemWidget.isMyMessage);
                  verify(chatItemWidget.message === message);
                  verify(chatItemWidget.isMyMessage === isMyMessage);
                  console.log("TestSetMessage executed successfully with empty message");
              }

              function test_testSetMessageAdditional3() {
                  console.log("Running testSetMessage with null message");
                  var message = null;
                  var isMyMessage = true;
                  var chatItemWidget = createChatItemWidget();
                  chatItemWidget.setMessage(message, isMyMessage);
                  console.log("Message set to:", chatItemWidget.message);
                  console.log("isMyMessage set to:", chatItemWidget.isMyMessage);
                  verify(chatItemWidget.message === message);
                  verify(chatItemWidget.isMyMessage === isMyMessage);
                  console.log("TestSetMessage executed successfully with null message");
              }
    }
}
