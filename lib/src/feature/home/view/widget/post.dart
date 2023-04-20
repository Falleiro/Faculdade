import 'package:flutter/material.dart';
import 'package:insta_clone/src/component/Minha_app_bar.dart';

class UserPost extends StatelessWidget {
  const UserPost({super.key});

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: MinhaAppBar(title: Text('Texto da home na app bar')),
      backgroundColor: Colors.blue,
      body: const Center(
        child: Text('POST', style: TextStyle(fontSize: 48)),
      ),
    );
  }
}
