import 'package:flutter/material.dart';
import 'burron_row.dart';
import 'button.dart';

class Keyboard extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return Container(
      height: 500,
      child: Column(
        children: <Widget>[
          ButtonRow([
            Button(text: 'AC'),
            Button(text: '+/-'),
            Button(text: '%'),
            Button.Operation(text: '/'),
          ]),
          ButtonRow([
            Button(text: '7'),
            Button(text: '8'),
            Button(text: '9'),
            Button.Operation(text: 'x'),
          ]),
          ButtonRow([
            Button(text: '4'),
            Button(text: '5'),
            Button(text: '6'),
            Button.Operation(text: '-'),
          ]),
          ButtonRow([
            Button(text: '1'),
            Button(text: '2'),
            Button(text: '3'),
            Button.Operation(text: '+'),
          ]),
          ButtonRow([
            Button.Big(text: '0'),
            Button(text: ','),
            Button.Operation(text: '='),
          ]),
        ],
      ),
    );
  }
}
